# HW7 — FileFilter 說明

## 系統架構與實作特色

### 1. 核心過濾器設計

- **抽象基礎類別 `FileFilter`**：定義純虛擬函式 `char transform(char)` 制定轉換合約，並提供 `doFilter(ifstream&, ofstream&)` 處理通用的檔案 I/O 迴圈。
- **子類別實作**：
  - `CopyFilter`：建立完全不變的原始檔案副本。
  - `UppercaseFilter`：將檔案中的英文字母 (ASCII) 全數轉換為大寫。
  - `EncryptionFilter`：凱撒加密過濾器。建構子接收一整數 `key`，僅對英文字母 (A-Z, a-z) 進行循環位移。
  - `LineBreakFilter`：**覆寫了 `doFilter`** 以精準處理跨平台的換行字元。能將 `\r` (CR)、`\n` (LF) 以及 `\r\n` (CRLF) 皆視為單一換行，並完美替換為單一空格。

### 2. 進階防護機制

- **暫存檔安全寫入 (Atomic-like Write)**：程式會先將結果寫入 `.tmp` 暫存檔，確認所有轉換與寫入皆無錯誤後，才覆寫或建立最終輸出檔。若中途發生例外錯誤，會自動清理暫存檔，避免留下損壞的檔案。
- **強大的 CLI 參數解析 (`input.cpp`)**：
  - 驗證輸入檔是否存在且為一般檔案 (禁止傳入資料夾)。
  - 防止輸入檔與輸出檔為同一實體檔案導致的自我覆寫錯誤。
  - 支援 `--force` 或 `-f` 參數，避免誤刪已存在的輸出檔。

---

## 檔案清單

- `main.cpp`：主程式進入點，負責流程控制與例外捕捉。
- `FileFilter.h` / `FileFilter.cpp`：抽象基礎類別與前三種過濾器 (複製、大寫、加密) 的實作。
- `LineBreakFilter.h` / `LineBreakFilter.cpp`：客製化處理移除換行符號的子類別實作。
- `input.h` / `input.cpp`：命令列參數解析、錯誤驗證與 `std::filesystem` 路徑檢查。
- `input.txt`：作業測試用輸入檔。

- 實作抽象類別 `FileFilter`，其純虛方法為 `char transform(char)`，並提供 `doFilter(ifstream&, ofstream&)`。
- 已實作子類：
  - `CopyFilter`：不變複製
  - `UppercaseFilter`：英文字母轉為大寫
  - `EncryptionFilter`：凱撒加密（對英文字母進行位移，建構子接收整數 key）
  - `LineBreakFilter`：每個換行 (CR / LF / CRLF) 替換為單一空格，CRLF 視為一個換行

---

## 編譯指令

```bash
g++ -g -std=c++17 -O2 main.cpp FileFilter.cpp LineBreakFilter.cpp input.cpp -o main.exe
```

---

## 執行範例

```bash
# 原樣複製
main.exe input.txt output_copy.txt copy

# 全大寫
main.exe input.txt output_upper.txt upper

# 凱撒加密 (key=3)
main.exe input.txt output_enc.txt encrypt 3

# 換行移除
main.exe input.txt output_oneline.txt linebreak
```

---
