#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <filesystem>

// 自訂標頭檔
#include "FileFilter.h"
#include "LineBreakFilter.h"
#include "input.h"

using namespace std;

void printUsage(const char *prog)
{
    cout << "使用方式: " << prog << " 輸入檔案 輸出檔案 篩選器 [key] [--force|-f]\n"
         << "篩選器:\n"
         << "  copy / 複製          - 原樣複製\n"
         << "  upper / 大寫         - 轉為大寫\n"
         << "  encrypt / 加密       - 凱撒加密，需要整數 key\n"
         << "  linebreak / 換行移除 - 將換行符替換為單一空格\n"
         << "選項:\n"
         << "  --force, -f         - 覆寫已存在的輸出檔\n";
}

int main(int argc, char *argv[])
{

    cout << "【檔案篩選器程式】\n";

    if (argc < 4)
    {
        printUsage(argv[0]);
        return 1;
    }

    // 解析並驗證命令列參數
    InputOptions opts;
    try
    {
        opts = parseAndValidateArgs(argc, argv);
    }
    catch (const exception &e)
    {
        cerr << "錯誤：" << e.what() << "\n";
        return 1;
    }

    // 以 binary 模式開檔以避免 CR/LF 平台轉換干擾換行符號判斷
    ifstream in(opts.inPath, ios::in | ios::binary);
    if (!in)
    {
        cerr << "無法開啟輸入檔案：" << opts.inPath << "\n";
        return 1;
    }

    // 使用暫存檔寫入，處理成功後再置換最終檔案，確保安全
    string outPath = opts.outPath;
    string tmpPath = outPath + ".tmp";

    ofstream out(tmpPath, ios::out | ios::binary | ios::trunc);
    if (!out)
    {
        cerr << "無法開啟暫存輸出檔案：" << tmpPath << "\n";
        return 1;
    }

    // 根據 filterName 建立對應的篩選器物件 (多型應用)
    unique_ptr<FileFilter> filter;

    if (opts.filterName == "copy")
    {
        filter = make_unique<CopyFilter>();
    }
    else if (opts.filterName == "upper")
    {
        filter = make_unique<UppercaseFilter>();
    }
    else if (opts.filterName == "encrypt")
    {
        filter = make_unique<EncryptionFilter>(opts.key);
    }
    else if (opts.filterName == "linebreak")
    {
        filter = make_unique<LineBreakFilter>();
    }
    else
    {
        cerr << "未知的篩選器：" << opts.filterName << "\n";
        printUsage(argv[0]);
        return 1;
    }

    // 執行過濾與檔案操作
    try
    {
        filter->doFilter(in, out);
        out.close(); // 寫入完成

        // 檢查最終輸出檔是否已存在
        if (filesystem::exists(outPath))
        {
            if (opts.force)
            {
                filesystem::remove(outPath); // 強制覆寫：先刪除舊檔案
            }
            else
            {
                throw runtime_error("輸出檔已存在，請加上 --force 或 -f 來覆寫：" + outPath);
            }
        }

        // 將暫存檔重新命名為最終的輸出檔
        filesystem::rename(tmpPath, outPath);
    }
    catch (const exception &e)
    {
        cerr << "處理時發生錯誤：" << e.what() << "\n";
        // 發生錯誤時清理殘留的暫存檔
        out.close();
        if (filesystem::exists(tmpPath))
        {
            filesystem::remove(tmpPath);
        }
        return 1;
    }

    cout << "完成：已將 \"" << opts.inPath << "\" 經由篩選 \"" << opts.filterName << "\" 輸出至 \"" << opts.outPath << "\"\n";
    return 0;
}