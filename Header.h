#pragma once
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

map<string, double> calculateAverage(const map<string, vector<int>>& students) {
    map<string, double> result;

    for (map<string, vector<int>>::const_iterator it = students.begin(); it != students.end(); ++it) {
        const string& name = it->first;
        const vector<int>& grades = it->second;

        if (grades.empty()) {
            throw invalid_argument("Student has no grades.");
        }

        int sum = 0;

        for (vector<int>::const_iterator vit = grades.begin(); vit != grades.end(); ++vit) {
            if (*vit < 0) {
                throw invalid_argument("Negative grade found.");
            }

            sum += *vit;
        }

        result[name] = static_cast<double>(sum) / grades.size();
    }

    return result;
}