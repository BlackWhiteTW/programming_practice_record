#pragma once

#include "Publication.h"

#include <string>

using namespace std;

// journal Ãþ§O Ä~©Ó¦Û Publication
class Journal : public Publication
{
private:
    int month;
    string ISSN;
    double impactFactor;
    double annualSubscription;

public:
    Journal();
    ~Journal();

    void input_month();
    void input_ISSN();
    void input_impactFactor();
    void input_annualSubscription();

    void input() override;
    void display() const override;
};
