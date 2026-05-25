#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() : width(), height() {}
Rectangle::Rectangle(const Length &w, const Length &h) : width(w), height(h) {}

// 互動式輸入：提示使用者輸入寬度與高度
void Rectangle::input()
{
    cout << "請輸入寬度:\n";
    width.input();
    cout << "請輸入高度:\n";
    height.input();
}

// 顯示矩形資訊
void Rectangle::display() const
{
    cout << "矩形寬度: ";
    width.display();
    cout << "\n";
    cout << "矩形高度: ";
    height.display();
    cout << "\n";
    cout << "周長 (cm): " << perimeter() << "\n";
    cout << "面積 (cm^2): " << area() << "\n";
}

// 面積（平方公分）
double Rectangle::area() const
{
    return width * height; // returns cm^2
}

// 周長（公分）
double Rectangle::perimeter() const
{
    double w_cm = static_cast<double>(width.totalMillimeters()) / 10.0;
    double h_cm = static_cast<double>(height.totalMillimeters()) / 10.0;
    return 2.0 * (w_cm + h_cm);
}