#pragma once

#include "Publication.h"

#include <string>

using namespace std;

// magazine Ãþ§O Ä~©Ó¦Û Publication
class Magazine : public Publication
{
private:
    int month;
    string editor;
    double annualSubscription;

public:
    Magazine();
    ~Magazine();

    void input() override;
    void display() const override;
};
