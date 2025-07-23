#include "file.h"
#include "utils.h"

// 从文件读取客户数据
Customer* readDataManagement(const std::string& file) {
    std::ifstream ifs(file);
    if (!ifs.is_open()) {
        std::ofstream ofs(file); // 如果文件不存在则创建
        std::cout << "文件不存在，创建文件成功！" << std::endl;
        ofs.close();
        return nullptr;
    }

    Customer* head = nullptr;
    Customer** tail = &head;

    while (ifs.peek() != EOF) {
        Customer* p = new Customer();
        ifs >> p->number >> p->account >> p->name;
        ifs >> p->depositSize;
        p->deposit.resize(p->depositSize);
        for (int i = 0; i < p->depositSize; ++i) {
            ifs >> p->deposit[i].depositAmount >> p->deposit[i].depositRateOfInterest;
        }
        ifs >> p->loansSize;
        p->loans.resize(p->loansSize);
        for (int i = 0; i < p->loansSize; ++i) {
            ifs >> p->loans[i].loansAmount >> p->loans[i].loansRateOfInterest;
        }
        ifs >> p->balance >> p->customerType >> p->subAccount;
        
        (*tail) = p;
        tail = &p->next;
    }

    ifs.close();
    return head;
}

// 将客户数据写入文件
void writeDataManagement(Customer* L, const std::string& file) {
    std::ofstream ofs(file);
    while (L != nullptr) {
        ofs << L->number << " " << L->account << " " << L->name << std::endl;
        ofs << L->depositSize << std::endl;
        for (const auto& dp : L->deposit) {
            ofs << dp.depositAmount << " " << dp.depositRateOfInterest << " ";
        }
        ofs << std::endl << L->loansSize << std::endl;
        for (const auto& loan : L->loans) {
            ofs << loan.loansAmount << " " << loan.loansRateOfInterest << " ";
        }
        ofs << std::endl << L->balance << " " << L->customerType << " " << L->subAccount << std::endl << std::endl;
        L = L->next;
    }
    ofs.close();
}

// 释放客户链表内存
void freeList(Customer* head) {
    while (head != nullptr) {
        Customer* temp = head;
        head = head->next;
        delete temp;
    }
}

// 客户资料文件管理主函数
void FileMain(customerAccount& L) {
    clearScreen();
    displayBankLogo();
    std::cout << "【客户资料文件管理】" << std::endl << std::endl;
    
    int choice;
    std::string filename;
    
    while (true) {
        std::cout << "\n请选择操作：" << std::endl;
        std::cout << "1. 保存客户数据到文件" << std::endl;
        std::cout << "2. 从文件读取客户数据" << std::endl;
        std::cout << "3. 返回主菜单" << std::endl;
        std::cout << "请输入选项(1-3): ";
        
        choice = safeInputInteger();
        
        switch (choice) {
            case 1:
                std::cout << "请输入要保存的文件名: ";
                std::cin >> filename;
                if (L && L->next) {
                    writeDataManagement(L->next, filename);
                    std::cout << "数据保存成功！" << std::endl;
                } else {
                    std::cout << "当前没有客户数据可保存！" << std::endl;
                }
                break;
                
            case 2:
                std::cout << "请输入要读取的文件名: ";
                std::cin >> filename;
                {
                    Customer* head = readDataManagement(filename);
                    if (head) {
                        // 释放当前链表
                        if (L && L->next) {
                            Customer* current = L->next;
                            while (current) {
                                Customer* temp = current;
                                current = current->next;
                                delete temp;
                            }
                            L->next = nullptr;
                        }
                        
                        // 将读取的数据链接到当前链表
                        L->next = head;
                        std::cout << "数据读取成功！" << std::endl;
                    } else {
                        std::cout << "文件为空或不存在有效数据！" << std::endl;
                    }
                }
                break;
                
            case 3:
                return;
                
            default:
                std::cout << "无效的选项，请重新输入！" << std::endl;
        }
        
        pauseAndContinue();
    }
}