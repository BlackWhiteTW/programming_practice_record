#pragma once

#include "Length.h"

#include <iostream>

// Rectangle 表示寬度與高度，並提供周長與面積計算
class Rectangle
{
private:
    Length width;  // 寬度
    Length height; // 高度
public:
    Rectangle();
    Rectangle(const Length &w, const Length &h);
    // 互動式輸入矩形尺寸
    void input();
    // 顯示矩形資訊：寬、高、周長、面積
    void display() const;
    // 回傳面積（平方公分）
    double area() const;
    // 回傳周長（公分）
    double perimeter() const;
};
