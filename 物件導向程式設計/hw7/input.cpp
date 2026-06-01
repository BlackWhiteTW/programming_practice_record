#include "input.h"

#include <string>
#include <stdexcept>
#include <filesystem>

using namespace std;

namespace fs = filesystem;

InputOptions parseAndValidateArgs(int argc, char *argv[])
{
    if (argc < 4)
        throw invalid_argument("參數不足");

    InputOptions opts;
    opts.inPath = argv[1];
    opts.outPath = argv[2];
    opts.filterName = argv[3];

    for (int i = 4; i < argc; ++i)
    {
        string a = argv[i];
        if (a == "--force" || a == "-f")
        {
            opts.force = true;
            continue;
        }

        if ((opts.filterName == "encrypt" || opts.filterName == "加密") && !opts.keyProvided)
        {
            try
            {
                size_t pos = 0;
                opts.key = stoi(a, &pos);
                if (pos != a.size())
                    throw invalid_argument("金鑰格式錯誤");
                opts.keyProvided = true;
            }
            catch (...)
            {
                throw invalid_argument(string("無效的加密金鑰：") + a);
            }
            continue;
        }

        throw invalid_argument(string("未知參數：") + a);
    }

    if ((opts.filterName == "encrypt" || opts.filterName == "加密") && !opts.keyProvided)
    {
        throw invalid_argument("encrypt 篩選器需要數字金鑰");
    }

    fs::path inPathObj(opts.inPath);
    fs::path outPathObj(opts.outPath);

    if (!fs::exists(inPathObj) || !fs::is_regular_file(inPathObj))
    {
        throw invalid_argument(string("輸入檔不存在或不是一般檔案：") + opts.inPath);
    }

    if (outPathObj.has_parent_path())
    {
        fs::path parent = outPathObj.parent_path();
        if (!fs::exists(parent) || !fs::is_directory(parent))
        {
            throw invalid_argument(string("輸出目錄不存在：") + parent.string());
        }
    }

    if (fs::exists(outPathObj))
    {
        if (fs::is_directory(outPathObj))
        {
            throw invalid_argument(string("輸出路徑是目錄，請指定檔案：") + opts.outPath);
        }

        if (fs::equivalent(inPathObj, outPathObj))
        {
            throw invalid_argument("輸入與輸出檔案相同，請指定不同的輸出檔案");
        }

        if (!opts.force)
        {
            throw invalid_argument("輸出檔已存在。如要覆寫請加上 --force 或 -f");
        }
    }

    return opts;
}