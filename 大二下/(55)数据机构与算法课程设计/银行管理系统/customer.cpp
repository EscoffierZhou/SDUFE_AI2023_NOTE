#include "customer.h"
#include "utils.h"

void InitCustomer(customerAccount& L) {
    L = new Customer;
    L->next = NULL;
    L->number = 0;
}

void creatAccount(customerAccount L) {
    clearScreen();
    displayBankLogo();
    std::cout << "【创建客户账户】" << std::endl << std::endl;
    
    // 创建头节点
    customerAccount p, r;
    r = L;
    
    // 创建初始链表
    std::cout << "请输入客户的姓名,账号,存款数额信息" << std::endl;
    bool t = 1;
    while (t) {
        // 1申请空间
        p = new Customer;
        
        // 2存入数据
        p->number = (r->number) + 1; // 序列号+1
        std::cout << "请输入客户姓名: ";
        std::cin >> p->name;
        
        std::cout << "请输入客户账号: ";
        std::cin >> p->account;
        
        std::cout << "请输入客户账户余额: ";
        std::cin >> p->balance;
        
        std::cout << "请输入客户类型(VIP/Non-VIP): ";
        std::cin >> p->customerType;
        
        // 3链接下一个节点
        p->next = NULL;
        r->next = p;
        r = p;
        
        // 4判断是否还要继续存入数据
        std::cout << "是否继续输入信息, 如果是输入1, 否则输入0: ";
        std::cin >> t;
    }
    
    std::cout << "客户账户创建成功！" << std::endl;
    pauseAndContinue();
}

void customerInsert(customerAccount q) {
    customerAccount t, p;
    t = q;
    while (t->next) {
        t = t->next;
    }
    
    p = new Customer;
    p->number = (t->number) + 1; // 序列号+1
    
    std::cout << "请输入客户姓名: ";
    std::cin >> p->name;
    
    std::cout << "请输入客户账号: ";
    std::cin >> p->account;
    
    std::cout << "请输入客户账户余额: ";
    std::cin >> p->balance;
    
    std::cout << "请输入客户类型(VIP/Non-VIP): ";
    std::cin >> p->customerType;
    
    t->next = p;
    p->next = NULL;
    
    std::cout << "客户信息插入成功！" << std::endl;
}

void customerDel(customerAccount q, int comAccount) {
    std::cout << "请输入要删除的客户的账户信息: ";
    customerAccount p = q;
    bool found = false;
    
    while (p && p->next) {
        if (p->next->account == comAccount) {
            customerAccount temp = p->next;
            p->next = temp->next;
            delete temp;
            found = true;
            std::cout << "客户删除成功！" << std::endl;
            break;
        }
        p = p->next;
    }
    
    if (!found) {
        std::cout << "未找到该账户，删除失败！" << std::endl;
    }
}

void searchName(customerAccount q, std::string searchedName) {
    bool judge = true;
    customerAccount p = q->next; // 跳过头节点
    
    std::cout << "\n查询结果：" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "序号\t姓名\t账户\t账户余额\t客户类型" << std::endl;
    
    while (p) {
        if (p->name == searchedName) {
            std::cout << p->number << "\t" << p->name << "\t" << p->account << "\t" 
                      << p->balance << "\t" << p->customerType << std::endl;
            judge = false;
        }
        p = p->next;
    }
    
    std::cout << "--------------------------------------------------------------" << std::endl;
    
    if (judge) {
        std::cout << "客户数据不存在" << std::endl;
    }
}

void searchAccount(customerAccount q, int searchedAccount) {
    bool judge = true;
    customerAccount p = q->next; // 跳过头节点
    
    std::cout << "\n查询结果：" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "序号\t姓名\t账户\t账户余额\t客户类型" << std::endl;
    
    while (p) {
        if (p->account == searchedAccount) {
            std::cout << p->number << "\t" << p->name << "\t" << p->account << "\t" 
                      << p->balance << "\t" << p->customerType << std::endl;
            judge = false;
            break;
        }
        p = p->next;
    }
    
    std::cout << "--------------------------------------------------------------" << std::endl;
    
    if (judge) {
        std::cout << "客户数据不存在" << std::endl;
    }
}

void searchAll(customerAccount& L) {
    customerAccount p;
    p = L->next; // 跳过头节点
    
    if (!p) {
        std::cout << "暂无客户信息！" << std::endl;
        return;
    }
    
    std::cout << "\n所有客户信息：" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "序号\t姓名\t账户\t账户余额\t客户类型" << std::endl;
    
    while (p) {
        std::cout << p->number << "\t" << p->name << "\t" << p->account << "\t" 
                  << p->balance << "\t" << p->customerType << std::endl;
        p = p->next;
    }
    
    std::cout << "--------------------------------------------------------------" << std::endl;
}

void createSubAccount() {
    // 待实现
    std::cout << "分账户功能尚未实现" << std::endl;
}

void customerSystem() {
    clearScreen();
    displayBankLogo();
    std::cout << "【客户账户管理系统】" << std::endl << std::endl;
    
    customerAccount L;
    InitCustomer(L);
    
    int choice;
    while (true) {
        std::cout << "\n请选择操作：" << std::endl;
        std::cout << "1. 创建客户账户" << std::endl;
        std::cout << "2. 插入客户信息" << std::endl;
        std::cout << "3. 删除客户信息" << std::endl;
        std::cout << "4. 按姓名查询客户" << std::endl;
        std::cout << "5. 按账号查询客户" << std::endl;
        std::cout << "6. 查看所有客户" << std::endl;
        std::cout << "7. 返回主菜单" << std::endl;
        std::cout << "请输入选项(1-7): ";
        
        choice = safeInputInteger();
        
        switch (choice) {
            case 1:
                creatAccount(L);
                break;
            case 2:
                customerInsert(L);
                break;
            case 3: {
                int account;
                std::cout << "请输入要删除的客户账号: ";
                std::cin >> account;
                customerDel(L, account);
                break;
            }
            case 4: {
                std::string name;
                std::cout << "请输入要查询的客户姓名: ";
                std::cin >> name;
                searchName(L, name);
                break;
            }
            case 5: {
                int account;
                std::cout << "请输入要查询的客户账号: ";
                std::cin >> account;
                searchAccount(L, account);
                break;
            }
            case 6:
                searchAll(L);
                break;
            case 7:
                destoryAccount(L);
                return;
            default:
                std::cout << "无效选项，请重新输入！" << std::endl;
        }
    }
}

void destoryAccount(customerAccount L) {
    customerAccount p, q;
    p = L->next;
    
    while (p) {
        q = p;
        p = p->next;
        delete q;
    }
    
    L->next = NULL;
    delete L;
}