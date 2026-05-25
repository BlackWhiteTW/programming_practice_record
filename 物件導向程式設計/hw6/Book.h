#pragma once

#include "Publication.h"

#include <string>

using namespace std;

// book Ãþ§O Ä~©Ó¦Û Publication
class Book : public Publication
{
private:
    string author;
    string ISBN;
    double price;

public:
    Book();
    ~Book();

    void input() override;
    void display() const override;
};
