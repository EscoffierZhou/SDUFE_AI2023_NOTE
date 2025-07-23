#include "category.h"
#include "utils.h"

// 打印链表内容并释放链表内存
void printAndFreeList(Catagory* head, const std::string& listName) {
    if (head == nullptr || head->next == nullptr) return;

    std::cout << listName << "有：" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    Catagory* current = head->next; // 跳过头节点
    while (current != nullptr) {
        std::cout << "序号:" << current->number
            << " 账号:" << current->account
            << " 用户姓名:" << current->name << std::endl;
        Catagory* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    std::cout << "--------------------------------------------------------------" << std::endl;
    delete head; // 删除头节点
}

void isVip(customerAccount& p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【客户分类系统】" << std::endl << std::endl;
    
    // 创建两个空节点作为VIP和非VIP链表的头节点
    Catagory* vipHead = new Catagory{0, 0, "", nullptr};
    Catagory* nonVipHead = new Catagory{0, 0, "", nullptr};

    // 检查 p 是否为空，假设第一个节点是空节点，从第二个节点开始
    if (p == nullptr || p->next == nullptr) {
        std::cout << "链表为空或只有一个空节点" << std::endl;
        delete vipHead;
        delete nonVipHead;
        pauseAndContinue();
        return;
    }

    // 使用临时指针进行遍历
    customerAccount temp = p->next; // 只复制指针

    while (temp != nullptr) {
        Catagory* c = new Catagory();
        c->account = temp->account;
        c->name = temp->name;
        c->number = temp->number;
        c->next = nullptr;

        if (temp->customerType == "VIP") {
            // 将新节点添加到VIP链表末尾
            Catagory* t = vipHead;
            while (t->next != nullptr) {
                t = t->next;
            }
            t->next = c;
        } else {
            // 将新节点添加到非VIP链表末尾
            Catagory* t = nonVipHead;
            while (t->next != nullptr) {
                t = t->next;
            }
            t->next = c;
        }

        temp = temp->next; // 移动到下一个节点
    }

    // 输出并清理VIP客户信息
    printAndFreeList(vipHead, "VIP客户");

    // 输出并清理非VIP客户信息
    printAndFreeList(nonVipHead, "普通客户");
    
    pauseAndContinue();
}