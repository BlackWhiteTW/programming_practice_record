#ifndef LINEBREAKFILTER_H
#define LINEBREAKFILTER_H

#include "FileFilter.h"

#include <fstream>

using namespace std;

// LineBreakFilter: 將檔案中的換行（\r, \n, CRLF）替換為單一空格
// - CRLF 視為一個換行
class LineBreakFilter : public FileFilter
{
public:
    LineBreakFilter() = default;
    char transform(char ch) override;
    void doFilter(ifstream &in, ofstream &out) override;
};

#endif