#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> scoreCount = {
        {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0}, {'K', 0}};

    int score;
    while (cin >> score && score != -1)
    {
        if (score >= 0 && score <= 9)
            scoreCount['A']++;
        else if (score >= 10 && score <= 19)
            scoreCount['B']++;
        else if (score >= 20 && score <= 29)
            scoreCount['C']++;
        else if (score >= 30 && score <= 39)
            scoreCount['D']++;
        else if (score >= 40 && score <= 49)
            scoreCount['E']++;
        else if (score >= 50 && score <= 59)
            scoreCount['F']++;
        else if (score >= 60 && score <= 69)
            scoreCount['G']++;
        else if (score >= 70 && score <= 79)
            scoreCount['H']++;
        else if (score >= 80 && score <= 89)
            scoreCount['I']++;
        else if (score >= 90 && score <= 99)
            scoreCount['J']++;
        else if (score == 100)
            scoreCount['K']++;
    }

    for (char c = 'A'; c <= 'K'; c++)
    {
        cout << c << "_" << scoreCount[c] << endl;
    }

    return 0;
}
