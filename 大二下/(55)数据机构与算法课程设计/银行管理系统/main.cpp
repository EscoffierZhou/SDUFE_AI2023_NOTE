#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "employee.h"
#include "customer.h"
#include "transaction.h"
#include "queue.h"
#include "branch.h"
#include "file.h"
#include "category.h"
#include "utils.h"

int main() {
    // 初始化客户链表
    customerAccount L;
    InitCustomer(L);
    
    int MainDecision;
    
    while (true) {
        clearScreen();
        displayBankLogo();
        
        std::cout << "~~~~欢迎您来到主界面~~~~" << std::endl;
        std::cout << "请输入需要实现功能的编码" << std::endl;
        std::cout << "1——职员管理     2——开户    3——存取贷款" << std::endl;
        std::cout << "4——业务查询     5——排队    6——网点查询" << std::endl;
        std::cout << "7——资料管理     8——资料查询           " << std::endl;
        std::cout << "0——退出系统" << std::endl;
        
        std::cin >> MainDecision;
        
        switch (MainDecision) {
            case 1:
                EmployeeMain();
                break;
            case 2:
                std::cout << "现在演示开户操作" << std::endl;
                creatAccount(L);
                break;
            case 3:
                std::cout << "现在演示存款贷款" << std::endl;
                function3(L);
                break;
            case 4:
                // 业务查询功能
                // searchService();
                std::cout << "业务查询功能尚未实现" << std::endl;
                pauseAndContinue();
                break;
            case 5:
                QueueMain();
                break;
            case 6:
                mainwork();
                break;
            case 7:
                FileMain(L);
                break;
            case 8:
                isVip(L);
                break;
            case 0:
                std::cout << "感谢使用银行管理系统，再见！" << std::endl;
                return 0;
            default:
                std::cout << "输入有误，请重新输入" << std::endl;
                pauseAndContinue();
        }
    }
    
    return 0;
}