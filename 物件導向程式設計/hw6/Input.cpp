#include "Input.h"

#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdlib>

using namespace std;

input::input() {}

input::~input() {}

string input::input_str()
{
    return input_str("");
}

string input::input_str(const string &prompt)
{
    while (true)
    {
        if (!prompt.empty())
        {
            cout << prompt;
        }

        string line;
        if (!getline(cin >> ws, line))
        {
            exit(0);
        }

        bool allSpace = true;
        for (char ch : line)
        {
            if (!isspace(static_cast<unsigned char>(ch)))
            {
                allSpace = false;
                break;
            }
        }

        if (!line.empty() && !allSpace)
        {
            return line;
        }

        cout << "輸入的字串為空，請重新輸入。" << endl;
    }
}

int input::input_i(int a, int b)
{
    return input_i("", a, b);
}

int input::input_i(const string &prompt, int a, int b)
{
    while (true)
    {
        if (!prompt.empty())
        {
            cout << prompt;
        }

        string line;
        if (!getline(cin >> ws, line))
        {
            exit(0);
        }

        stringstream ss(line);
        int value;
        char extra;
        if (!(ss >> value) || (ss >> extra))
        {
            cout << "輸入的不是整數，請重新輸入。" << endl;
            continue;
        }

        if (value < a || value > b)
        {
            cout << "輸入的數字不在範圍內，請重新輸入。" << endl;
            continue;
        }

        return value;
    }
}

double input::input_d()
{
    return input_d("");
}

double input::input_d(const string &prompt)
{
    while (true)
    {
        if (!prompt.empty())
        {
            cout << prompt;
        }

        string line;
        if (!getline(cin >> ws, line))
        {
            exit(0);
        }

        stringstream ss(line);
        double value;
        char extra;
        if (!(ss >> value) || (ss >> extra))
        {
            cout << "輸入的不是浮點數，請重新輸入。" << endl;
            continue;
        }

        return value;
    }
}