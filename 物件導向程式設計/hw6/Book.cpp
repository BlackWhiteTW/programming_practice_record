#include "Book.h"
#include "Input.h"

#include <iostream>

using namespace std;

Book::Book()
    : author(""), ISBN(""), price(0.0) {}

Book::~Book() {}

void Book::input()
{
    Publication::input();
    author = input::input_str("請輸入作者：");
    ISBN = input::input_str("請輸入 ISBN：");
    price = input::input_d("請輸入價格：");
}

void Book::display() const
{
    cout << "=== 書籍 ===" << endl;
    Publication::display();
    cout << "作者：" << author << '\n';
    cout << "ISBN：" << ISBN << '\n';
    cout << "價格：" << price << '\n';
}
