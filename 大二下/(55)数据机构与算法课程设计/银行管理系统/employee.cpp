#include "employee.h"
#include "utils.h"

Node* creatList() {
    Node* headnode = new Node;
    headnode->next = NULL;
    return headnode;
}

Node* creatNode(std::string employeename, std::string gender, std::string worknumber, int age, long long int phonenumber) {
    Node* newnode = new Node;
    newnode->employeename = employeename;
    newnode->gender = gender;
    newnode->worknumber = worknumber;
    newnode->age = age;
    newnode->phonenumber = phonenumber;
    newnode->average = 0;
    newnode->count = 0;
    newnode->next = NULL;
    return newnode;
}

void insert(Node* headnode, std::string employeename, std::string gender, std::string worknumber, int age, long long int phonenumber) {
    Node* newnode = creatNode(employeename, gender, worknumber, age, phonenumber);
    newnode->next = headnode->next;
    headnode->next = newnode;
}

void del(Node* headnode, std::string worknumber) {
    Node* fro = headnode;
    Node* pMove = headnode->next;
    if (pMove == NULL) {
        std::cout << "职员信息为空" << std::endl;
    }
    else {
        while (pMove->worknumber.compare(worknumber) != 0) {
            fro = pMove;
            pMove = pMove->next;
            if (pMove == NULL) {
                std::cout << "工号输入错误或并无此人！" << std::endl;
                break;
            }
        }
        if (pMove != NULL) {
            fro->next = pMove->next;
            delete(pMove);
            std::cout << "删除成功！" << std::endl;
        }
    }
}

void selectedshow(Node* headnode, std::string worknumber) {
    Node* pMove = headnode->next;
    if (pMove == NULL) {
        std::cout << "没有职员，无法查询！" << std::endl;
    }
    else {
        while (pMove != NULL) {
            if (pMove->worknumber.compare(worknumber) == 0) {
                std::cout << "此职员信息为：（姓名，性别，工号，年龄，手机号，平均评分）" << std::endl;
                std::cout << pMove->employeename << " " << pMove->gender << " " << pMove->worknumber << " " 
                          << pMove->age << " " << pMove->phonenumber << " " << pMove->average << std::endl;
                break;
            }
            else {
                pMove = pMove->next;
                if (pMove == NULL) {
                    std::cout << "工号输入错误或并无此人！" << std::endl;
                    break;
                }
            }
        }
    }
}

void show(Node* headnode) {
    Node* pMove = headnode->next;
    if (pMove == NULL) {
        std::cout << "暂无职员信息！" << std::endl;
        return;
    }
    
    std::cout << "全体职员信息为：（姓名，性别，工号，年龄，手机号，平均评分）" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    while (pMove != NULL) {
        std::cout << pMove->employeename << " " << pMove->gender << " " << pMove->worknumber << " " 
                  << pMove->age << " " << pMove->phonenumber << " " << pMove->average << std::endl;
        pMove = pMove->next;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
}

void EmployeeMain() {
    clearScreen();
    displayBankLogo();
    std::cout << "【职员管理系统】" << std::endl << std::endl;
    
    Node* List = creatList();
    std::string employeename; // 姓名
    std::string gender;       // 性别，man或woman
    std::string worknumber;   // 工号
    int age;                  // 年龄
    long long int phonenumber; // 手机号
    std::string option;
    int choose;
    
    while (true) {
        std::cout << "\n请选择操作：" << std::endl;
        std::cout << "1. 插入职员信息" << std::endl;
        std::cout << "2. 删除职员信息" << std::endl;
        std::cout << "3. 查询职员信息" << std::endl;
        std::cout << "4. 返回主菜单" << std::endl;
        std::cout << "请输入选项(1-4): ";
        
        choose = safeInputInteger();
        
        switch (choose) {
            case 1: {
                std::cout << "\n请输入职员信息（姓名，性别，工号，年龄，手机号）" << std::endl;
                std::cin >> employeename >> gender >> worknumber >> age >> phonenumber;
                insert(List, employeename, gender, worknumber, age, phonenumber);
                std::cout << "职员信息添加成功！" << std::endl;
                
                while (true) {
                    std::cout << "是否继续插入职员信息？(yes/no): ";
                    std::cin >> option;
                    if (option == "yes") {
                        std::cout << "\n请输入职员信息（姓名，性别，工号，年龄，手机号）" << std::endl;
                        std::cin >> employeename >> gender >> worknumber >> age >> phonenumber;
                        insert(List, employeename, gender, worknumber, age, phonenumber);
                        std::cout << "职员信息添加成功！" << std::endl;
                    } else if (option == "no") {
                        break;
                    } else {
                        std::cout << "格式错误，请重新确认操作！" << std::endl;
                    }
                }
                break;
            }
            case 2: {
                std::cout << "\n请输入待删除职员的工号：" << std::endl;
                std::cin >> worknumber;
                del(List, worknumber);
                
                while (true) {
                    std::cout << "是否继续删除职员信息？(yes/no): ";
                    std::cin >> option;
                    if (option == "yes") {
                        std::cout << "\n请输入待删除职员的工号：" << std::endl;
                        std::cin >> worknumber;
                        del(List, worknumber);
                    } else if (option == "no") {
                        break;
                    } else {
                        std::cout << "格式错误，请重新确认操作！" << std::endl;
                    }
                }
                break;
            }
            case 3: {
                std::cout << "\n请选择查询方式：" << std::endl;
                std::cout << "1. 精准查询某一员工信息" << std::endl;
                std::cout << "2. 查询所有员工信息" << std::endl;
                std::cout << "请输入选项(1-2): ";
                
                int queryChoice = safeInputInteger();
                
                if (queryChoice == 1) {
                    std::cout << "请输入此员工工号：" << std::endl;
                    std::cin >> worknumber;
                    selectedshow(List, worknumber);
                } else if (queryChoice == 2) {
                    show(List);
                } else {
                    std::cout << "无法判断类别，请重新输入！" << std::endl;
                    continue;
                }
                
                while (true) {
                    std::cout << "是否继续查询职员信息？(yes/no): ";
                    std::cin >> option;
                    if (option == "yes") {
                        std::cout << "\n请选择查询方式：" << std::endl;
                        std::cout << "1. 精准查询某一员工信息" << std::endl;
                        std::cout << "2. 查询所有员工信息" << std::endl;
                        std::cout << "请输入选项(1-2): ";
                        
                        queryChoice = safeInputInteger();
                        
                        if (queryChoice == 1) {
                            std::cout << "请输入此员工工号：" << std::endl;
                            std::cin >> worknumber;
                            selectedshow(List, worknumber);
                        } else if (queryChoice == 2) {
                            show(List);
                        } else {
                            std::cout << "无法判断类别，请重新输入！" << std::endl;
                        }
                    } else if (option == "no") {
                        break;
                    } else {
                        std::cout << "格式错误，请重新确认操作！" << std::endl;
                    }
                }
                break;
            }
            case 4:
                // 释放链表内存
                Node* current = List->next;
                while (current != NULL) {
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                }
                delete List;
                return;
        }
    }
}