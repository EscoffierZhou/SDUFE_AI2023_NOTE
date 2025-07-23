#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

// 存款结构体
struct Deposit {
    double depositAmount;        // 存款数额
    double depositRateOfInterest; // 存款利率
};

// 贷款结构体
struct Loans {
    double loansAmount;         // 贷款数额
    double loansRateOfInterest; // 贷款利率
};

// 客户账号管理系统结构体
typedef struct Customer {
    int number;                    // 序号
    int account;                   // 账号
    std::string name;              // 用户姓名
    int depositSize = 0;
    std::vector<Deposit> deposit;  // 存款
    int loansSize = 0;
    std::vector<Loans> loans;      // 贷款
    double balance = 0;            // 余额
    std::string customerType = "Non-VIP"; // 客户类别,默认为普通
    bool subAccount = false;       // 是否有分帐户,默认为无
    struct Customer* next = nullptr; // 链表,指向下一个节点
} *customerAccount;

// 初始化客户链表
void InitCustomer(customerAccount& L);

// 创建客户账户
void creatAccount(customerAccount L);

// 插入客户
void customerInsert(customerAccount q);

// 根据账号删除客户
void customerDel(customerAccount q, int comAccount);

// 根据名字查询客户
void searchName(customerAccount q, std::string searchedName);

// 根据账户查询客户
void searchAccount(customerAccount q, int searchedAccount);

// 打印所有客户信息
void searchAll(customerAccount& L);

// 创建客户的分帐户
void createSubAccount();

// 客户账户管理系统主函数
void customerSystem();

// 销毁用户数据表
void destoryAccount(customerAccount L);

#endif // CUSTOMER_H