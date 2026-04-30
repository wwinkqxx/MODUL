#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

vector<Product> readJson(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("File not found!");
    }

    json j;
    file >> j;

    vector<Product> products;

    for (const auto& item : j) {
        if (!item.contains("name") || !item.contains("price") || !item.contains("quantity")) {
            throw runtime_error("Missing field in JSON object!");
        }

        if (!item["name"].is_string() ||
            !item["price"].is_number() ||
            !item["quantity"].is_number_integer()) {
            throw runtime_error("Invalid data type in JSON!");
        }

        products.push_back({
            item["name"],
            item["price"],
            item["quantity"]
            });
    }

    return products;
}

void writeCsv(const string& filename, const vector<Product>& products) {
    ofstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to create CSV file!");
    }

    file << "name,price,quantity\n";

    for (const auto& p : products) {
        file << p.name << ","
            << p.price << ","
            << p.quantity << "\n";
    }
}

int main() {
    try {
        vector<Product> products = readJson("data.json");

        products.erase(
            remove_if(products.begin(), products.end(),
                [](const Product& p) {
                    return p.quantity == 0;
                }),
            products.end()
        );

        writeCsv("output.csv", products);

        cout << "Program finished" << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}