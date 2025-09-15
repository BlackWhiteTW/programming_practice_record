#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b ;
    string s ;
    char c ;
    cout << "Please input your name.... ";
    cin >> s;

    cout << "Please select your department.... (a:資工 b:電機 c:電子) ";
    cin >> c;

    cout << "Please input your score on test 1 .... ";
    cin >> a;

    cout << "Please input your score on test 2 .... ";
    cin >> b;

    cout << "|-------------------------------------------|" << endl;
    cout << "|   Name   |Department|Test 1|Test 2|Average|" << endl;
    cout << "|-------------------------------------------|" << endl;
    cout << "|" << setw(10) << left << s << "|" << setw(10) << c << "|" << setw(6) << right << a << "|" << setw(6) << b << "|" << setw(7) << fixed << setprecision(2) << (a+b)/2.0 << "|" << endl;
    cout << "|-------------------------------------------|" << endl;

    system("pause");
    return 0;
}