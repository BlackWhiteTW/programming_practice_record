#include <iostream>
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"

int main()
{
    std::cout << "出版品類別範例程式\n";

    Book b;
    std::cout << "請輸入書籍資料：\n";
    b.input();
    std::cout << '\n';

    Journal j;
    std::cout << "請輸入期刊資料：\n";
    j.input();
    std::cout << '\n';

    Magazine m;
    std::cout << "請輸入雜誌資料：\n";
    m.input();
    std::cout << '\n';

    std::cout << "\n顯示輸入的資料：\n\n";
    b.display();
    std::cout << '\n';
    j.display();
    std::cout << '\n';
    m.display();

    return 0;
}
