#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

// 职员结构体
struct Node {
    std::string employeename; // 姓名
    std::string gender;       // 性别，man或woman
    std::string worknumber;   // 工号
    int age;                  // 年龄
    long long int phonenumber; // 手机号
    int average;              // 平均打分
    int count;                // 人数
    Node* next;
};

// 创建职员链表头节点
Node* creatList();

// 创建新职员节点
Node* creatNode(std::string employeename, std::string gender, std::string worknumber, int age, long long int phonenumber);

// 插入职员信息
void insert(Node* headnode, std::string employeename, std::string gender, std::string worknumber, int age, long long int phonenumber);

// 删除职员信息
void del(Node* headnode, std::string worknumber);

// 查询特定职员信息
void selectedshow(Node* headnode, std::string worknumber);

// 显示所有职员信息
void show(Node* headnode);

// 职员管理主函数
void EmployeeMain();

#endif // EMPLOYEE_H