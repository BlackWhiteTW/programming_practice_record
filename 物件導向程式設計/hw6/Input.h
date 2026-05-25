#pragma once

#include <string>
#include <limits>

using namespace std;

// 基底類別 input 輸入用途 檢查輸入的有效性
class input
{
public:
    input();
    ~input();
    static string input_str();
    static string input_str(const string &prompt);
    static int input_i(int a = numeric_limits<int>::min(), int b = numeric_limits<int>::max());
    static int input_i(const string &prompt, int a = numeric_limits<int>::min(), int b = numeric_limits<int>::max());
    static double input_d();
    static double input_d(const string &prompt);
};