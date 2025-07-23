#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"

// 存款
void deposit(customerAccount p);

// 取款
void withdrawal(customerAccount p);

// 账户余额查询
void balanceInquiry(customerAccount p);

// 贷款
void loans(customerAccount p);

// 计算利息
void calculateInterest(customerAccount p);

// 存取款业务管理总入口
void function3(customerAccount& p);

#endif // TRANSACTION_H