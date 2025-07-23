#include "queue.h"
#include "utils.h"

// 全局变量
std::vector<customerAccount1> V; // VIP客户队列
std::vector<customerAccount1> N; // 普通客户队列

customerAccount1* creatCus() {
    customerAccount1* newnode = new customerAccount1;
    newnode->account = 0;
    newnode->customerType = "non-VIP";
    newnode->depositAmount = 0;
    newnode->name = "0";
    newnode->next = NULL;
    newnode->number = 0;
    return newnode;
}

Node* creatNode() {
    Node* newnode = new Node;
    newnode->age = 0;
    newnode->average = 0;
    newnode->count = 0;
    newnode->employeename = "0";
    newnode->gender = "man";
    newnode->next = NULL;
    newnode->phonenumber = 0;
    newnode->worknumber = "0";
    return newnode;
}

void divide(customerAccount1* headnode, long long int account) {
    customerAccount1* pMove = headnode->next;
    if (pMove == NULL) {
        std::cout << "暂无客户，请建立客户档案！" << std::endl;
    }
    else {
        while (pMove != NULL) {
            if (pMove->account == account) {
                if (pMove->customerType.compare("VIP") == 0) {
                    V.push_back(*pMove);
                    std::cout << "已将客户 " << pMove->name << " 加入VIP队列" << std::endl;
                    break;
                }
                else if (pMove->customerType.compare("non-VIP") == 0) {
                    N.push_back(*pMove);
                    std::cout << "已将客户 " << pMove->name << " 加入普通队列" << std::endl;
                    break;
                }
                else {
                    std::cout << "账户类型异常！" << std::endl;
                }
            }
            pMove = pMove->next;
            if (pMove == NULL) {
                std::cout << "未找到该账号的客户！" << std::endl;
            }
        }
    }
}

void rownumber() {
    int Number = 1;
    std::vector<customerAccount1>::iterator it;
    
    // 先为VIP客户分配号码
    for (it = V.begin(); it != V.end(); it++) {
        (*it).number = Number;
        Number++;
    }
    
    // 再为普通客户分配号码
    for (it = N.begin(); it != N.end(); it++) {
        (*it).number = Number;
        Number++;
    }
    
    // 显示排队结果
    std::cout << "\n排队结果：" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    
    if (!V.empty()) {
        std::cout << "VIP客户队列：" << std::endl;
        for (it = V.begin(); it != V.end(); it++) {
            std::cout << "号码: " << (*it).number << ", 账号: " << (*it).account 
                      << ", 姓名: " << (*it).name << std::endl;
        }
    }
    
    if (!N.empty()) {
        std::cout << "普通客户队列：" << std::endl;
        for (it = N.begin(); it != N.end(); it++) {
            std::cout << "号码: " << (*it).number << ", 账号: " << (*it).account 
                      << ", 姓名: " << (*it).name << std::endl;
        }
    }
    
    std::cout << "--------------------------------------------------------------" << std::endl;
}

Node* selectedemployee(Node* headnode, std::string worknumber) {
    Node* pMove = headnode->next;
    if (pMove == NULL) {
        std::cout << "暂无职员！" << std::endl;
        return NULL;
    }
    else {
        while (pMove != NULL) {
            if (pMove->worknumber.compare(worknumber) == 0) {
                return pMove;
            }
            else {
                pMove = pMove->next;
                if (pMove == NULL) {
                    std::cout << "工号输入错误或并无此人！" << std::endl;
                }
            }
        }
    }
    return NULL;
}

void grade(Node* headnode, std::string worknumber, int score) {
    Node* pMove = selectedemployee(headnode, worknumber);
    long long int t;
    if (pMove != NULL) {
        t = pMove->average * pMove->count;
        t += score;
        pMove->count++;
        pMove->average = t / pMove->count;
        std::cout << "打分完毕！" << std::endl;
    }
    else {
        std::cout << "错误！无法打分！" << std::endl;
    }
}

void QueueMain() {
    clearScreen();
    displayBankLogo();
    std::cout << "【银行排队管理系统】" << std::endl << std::endl;
    
    // 清空之前的队列
    V.clear();
    N.clear();
    
    customerAccount1* Headnode = creatCus();
    Node* headnode = creatNode();
    
    // 模拟添加一些客户数据
    customerAccount1* customer1 = new customerAccount1;
    customer1->account = 10001;
    customer1->name = "张三";
    customer1->customerType = "VIP";
    customer1->next = NULL;
    
    customerAccount1* customer2 = new customerAccount1;
    customer2->account = 10002;
    customer2->name = "李四";
    customer2->customerType = "non-VIP";
    customer2->next = NULL;
    
    customerAccount1* customer3 = new customerAccount1;
    customer3->account = 10003;
    customer3->name = "王五";
    customer3->customerType = "VIP";
    customer3->next = NULL;
    
    // 链接客户
    Headnode->next = customer1;
    customer1->next = customer2;
    customer2->next = customer3;
    
    // 模拟添加一些职员数据
    Node* employee1 = new Node;
    employee1->employeename = "赵六";
    employee1->worknumber = "E001";
    employee1->average = 85;
    employee1->count = 10;
    employee1->next = NULL;
    
    headnode->next = employee1;
    
    int option1;
    int quantity;
    long long int Account;
    std::string worknumber1;
    int score;
    
    std::cout << "是否需要排号服务？（需要请输入1，不需要请输入2）" << std::endl;
    std::cin >> option1;
    
    if (option1 == 1) {
        std::cout << "请输入需要排号服务的人数：" << std::endl;
        std::cin >> quantity;
        
        std::cout << "请依次输入排队客户的账号：" << std::endl;
        for (int i = 0; i < quantity; i++) {
            std::cin >> Account;
            divide(Headnode, Account);
        }
        
        std::cout << "开始进行排号中..." << std::endl;
        rownumber();
        std::cout << "排号完毕！" << std::endl;
        
        // 客户选择服务
        std::cout << "\n模拟客户服务中..." << std::endl;
        std::cout << "客户服务完成！" << std::endl;
        
        std::cout << "是否为服务职员工号打分？（打分请按1，不打分请按2）" << std::endl;
        std::cin >> option1;
        
        if (option1 == 1) {
            std::cout << "请输入此职员工号：" << std::endl;
            std::cin >> worknumber1;
            std::cout << "请输入分数（满分100）" << std::endl;
            std::cin >> score;
            grade(headnode, worknumber1, score);
        }
    }
    
    // 释放内存
    customerAccount1* current = Headnode;
    while (current) {
        customerAccount1* temp = current;
        current = current->next;
        delete temp;
    }
    
    Node* currentNode = headnode;
    while (currentNode) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }
    
    pauseAndContinue();
}