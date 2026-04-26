#ifndef QUOTE_SYSTEM_UI_H
#define QUOTE_SYSTEM_UI_H

#include "QuoteSystemCore.h"

#include <string>

// 顯示主選單
void printMenu();

// 創建估價單物件
ServiceQuote createQuoteFromInput();

// 顯示查詢結果
void printQuotes(const std::vector<const ServiceQuote *> &quotes);

// 顯示所有估價單摘要
void printAllQuotes(const std::vector<ServiceQuote> &quotes);

#endif