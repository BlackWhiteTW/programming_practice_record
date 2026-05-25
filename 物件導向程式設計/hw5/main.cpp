#include "Length.h"
#include "Rectangle.h"

#include <iostream>

using namespace std;

int main()
{
    Length a, b;
    cout << "請輸入矩形的寬度：\n";
    a.input();
    cout << "請輸入矩形的長度：\n";
    b.input();

    cout << "\n矩形的寬度: ";
    a.display();
    cout << "\n矩形的長度: ";
    b.display();
    cout << "\n";
    Length c = a + b;
    cout << "A + B = ";
    c.display();
    cout << "\n";
    Rectangle r(a, b);
    cout << "\n矩形 r 的資訊:\n";
    r.display();

    return 0;
}