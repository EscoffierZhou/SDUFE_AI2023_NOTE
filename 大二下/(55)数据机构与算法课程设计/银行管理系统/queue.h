#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <vector>
#include "employee.h"

// 客户账户结构体（简化版，用于排队系统）
struct customerAccount1 {
    int number;                // 序号
    long long int account;     // 账号
    std::string name;          // 用户姓名
    double depositAmount;      // 存款数额
    std::string customerType;  // 客户类别,默认为普通
    customerAccount1* next;    // 链表,指向下一个节点
};

// 创建客户节点
customerAccount1* creatCus();

// 创建职员节点
Node* creatNode();

// 将客户分类到VIP或普通队列
void divide(customerAccount1* headnode, long long int account);

// 为客户分配排队号码
void rownumber();

// 查找特定工号的职员
Node* selectedemployee(Node* headnode, std::string worknumber);

// 为职员打分
void grade(Node* headnode, std::string worknumber, int score);

// 排队管理主函数
void QueueMain();

#endif // QUEUE_H