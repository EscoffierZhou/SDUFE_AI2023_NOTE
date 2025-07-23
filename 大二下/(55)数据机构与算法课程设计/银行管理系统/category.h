#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include "customer.h"

// 客户分类结构体
typedef struct Catagory {
    int number;  // 序号
    int account; // 账号
    std::string name; // 用户姓名
    Catagory* next = nullptr;
} Catagory;

// 打印链表内容并释放链表内存
void printAndFreeList(Catagory* head, const std::string& listName);

// 客户分类主函数
void isVip(customerAccount& p);

#endif // CATEGORY_H