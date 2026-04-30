#include "Header.h"

#include <stdexcept>

int main() {
    try {
        map<string, vector<int>> students;

        students["Anna"] = { 90, 85, 95 };
        students["Oleh"] = { 78, 82, 80 };
        students["Maria"] = { 100, 95, 98 };
        students["Ivan"] = { 70, 75, 72 };
       // students["Petro"] = {90, -5, 80}; 
        map<string, double> averages = calculateAverage(students);

        cout << "Students average grades:\n";

        for (map<string, double>::iterator it = averages.begin(); it != averages.end(); ++it) {
            cout << it->first << " -> " << it->second << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}