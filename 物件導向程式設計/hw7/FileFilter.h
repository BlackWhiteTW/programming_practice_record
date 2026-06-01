#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <fstream>

using namespace std;

// FileFilter 抽象類別

class FileFilter
{
public:
    virtual ~FileFilter() = default;
    virtual char transform(char ch) = 0;
    virtual void doFilter(ifstream &in, ofstream &out);
};

// 不改變內容的篩選器（複製）
class CopyFilter : public FileFilter
{
public:
    char transform(char ch) override;
};

// 將英文字母轉為大寫的篩選器
class UppercaseFilter : public FileFilter
{
public:
    char transform(char ch) override;
};

// 簡單的凱撒加密範例：只位移英文字母（A-Z, a-z）
class EncryptionFilter : public FileFilter
{
public:
    explicit EncryptionFilter(int key = 0);
    char transform(char ch) override;

private:
    int key_;
};

#endif
