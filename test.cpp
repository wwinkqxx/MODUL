#include "pch.h"
#include "C:\Users\Користувач\source\repos\modul21\Header.h"
#include <gtest/gtest.h>
#include <map>



TEST(Testcalculateavarege, calculateAverage) {
    map<string, vector<int>> students;

    students["Anna"] = { 90, 80, 100 };
    students["Oleh"] = { 70, 80, 90 };
    students["Maria"] = { 100, 100, 100 };

    map<string, double> result = calculateAverage(students);

    ASSERT_NEAR(90.0, result["Anna"], 0.001);
    ASSERT_NEAR(80.0, result["Oleh"], 0.001);
    ASSERT_NEAR(100.0, result["Maria"], 0.001);
}