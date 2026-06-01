#ifndef INPUT_H
#define INPUT_H

#include <string>

using namespace std;

struct InputOptions
{
    string inPath;
    string outPath;
    string filterName;
    bool force = false;
    bool keyProvided = false;
    int key = 0;
};

// 解析並驗證命令列參數；若參數不正確會拋出 invalid_argument
// 回傳 InputOptions，包含輸入/輸出路徑、篩選器名稱、是否強制覆寫
InputOptions parseAndValidateArgs(int argc, char *argv[]);

#endif
