#pragma once

#include <string>

using namespace std;

// 基底類別 Publication 宣告 共用 tutle volume year 成員變數
class Publication
{
protected:
    string title;
    int volume;
    int year;

public:
    Publication();
    virtual ~Publication();

    virtual void input();

    virtual void display() const;
};
