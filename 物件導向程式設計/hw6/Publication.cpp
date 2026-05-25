#include "Publication.h"
#include "Input.h"

#include <iostream>

using namespace std;

Publication::Publication()
    : title(""), volume(0), year(0) {}

Publication::~Publication() {}

// 基底類別的 input 和 display 方法
void Publication::input()
{
    title = input::input_str("請輸入標題：");
    volume = input::input_i("請輸入卷號：");
    year = input::input_i("請輸入年份：");
}

void Publication::display() const
{
    std::cout << "標題：" << title << '\n';
    std::cout << "卷號：" << volume << '\n';
    std::cout << "年份：" << year << '\n';
}
