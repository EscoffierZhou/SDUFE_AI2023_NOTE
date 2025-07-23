#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include "customer.h"

// 从文件读取客户数据
Customer* readDataManagement(const std::string& file);

// 将客户数据写入文件
void writeDataManagement(Customer* L, const std::string& file);

// 释放客户链表内存
void freeList(Customer* head);

// 客户资料文件管理主函数
void FileMain(customerAccount& L);

#endif // FILE_H