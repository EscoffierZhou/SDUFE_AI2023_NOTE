#include "transaction.h"
#include "utils.h"

void deposit(customerAccount p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【存款业务】" << std::endl << std::endl;
    
    std::cout << "直接存到账户余额中请输入1，选择存定期请输入2: ";
    int flag = 0;
    std::cin >> flag;
    
    if (flag == 1) {
        std::cout << "请输入存款金额：" << std::endl;
        double money;
        std::cin >> money;
        p->balance += money;
        std::cout << "存款成功！当前余额: " << p->balance << std::endl;
        return;
    }
    else if (flag != 2) {
        std::cout << "错误的输入！\n";
        return;
    }

    std::cout << "请选择您的存款方案（输入阿拉伯数字）：" << std::endl;
    std::cout << "方案1：存款年限：1年；利息：1.75%" << std::endl;
    std::cout << "方案2：存款年限：2年；利息：1.95%" << std::endl;
    std::cout << "方案3：存款年限：3年；利息：2.15%" << std::endl;
    std::cout << "方案4：存款年限：4年；利息：2.35%" << std::endl;
    std::cout << "方案5：存款年限：5年；利息：2.55%" << std::endl;
    
    int choice = 0;
    Deposit t;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            // 输入存款金额
            std::cout << "请输入存款金额：" << std::endl;
            std::cin >> t.depositAmount;
            t.depositRateOfInterest = 0.0175;
            p->deposit.push_back(t);
            std::cout << "存款成功！" << std::endl;
            break;
        case 2:
            // 输入存款金额
            std::cout << "请输入存款金额：" << std::endl;
            std::cin >> t.depositAmount;
            t.depositRateOfInterest = 0.0195 * 2;
            p->deposit.push_back(t);
            std::cout << "存款成功！" << std::endl;
            break;
        case 3:
            // 输入存款金额
            std::cout << "请输入存款金额：" << std::endl;
            std::cin >> t.depositAmount;
            t.depositRateOfInterest = 0.0215 * 3;
            p->deposit.push_back(t);
            std::cout << "存款成功！" << std::endl;
            break;
        case 4:
            // 输入存款金额
            std::cout << "请输入存款金额：" << std::endl;
            std::cin >> t.depositAmount;
            t.depositRateOfInterest = 0.0235 * 4;
            p->deposit.push_back(t);
            std::cout << "存款成功！" << std::endl;
            break;
        case 5:
            // 输入存款金额
            std::cout << "请输入存款金额：" << std::endl;
            std::cin >> t.depositAmount;
            t.depositRateOfInterest = 0.0255 * 5;
            p->deposit.push_back(t);
            std::cout << "存款成功！" << std::endl;
            break;
        default:
            std::cout << "没有此方案！" << std::endl;
            break;
    }
    p->depositSize = p->deposit.size();
}

// 取款
void withdrawal(customerAccount p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【取款业务】" << std::endl << std::endl;
    
    std::cout << "您是想要从存款中取款还是从账户余额中取款？从存款中取款请按1，从账户余额中取款请按2" << std::endl;
    int flag = 0;
    std::cin >> flag;
    
    if (flag == 1) {
        if (p->deposit.size() == 0) {
            std::cout << "您没有任何存款！" << std::endl;
            return;
        }
        
        std::cout << "您共有" << p->deposit.size() << "笔存款：" << std::endl;
        for (int i = 0; i < p->deposit.size(); i++) {
            std::cout << "第" << i + 1 << "笔存款：存款利率为：" << p->deposit[i].depositRateOfInterest;
            std::cout << " 存款数额为：" << p->deposit[i].depositAmount << std::endl;
        }
        
        std::cout << "您想要取出哪一笔？请输入阿拉伯数字\n";
        int c = 0;
        std::cin >> c;
        
        if (c > 0 && c <= p->deposit.size()) {
            auto e = p->deposit.begin() + (c - 1);
            p->deposit.erase(e);
            std::cout << "取款成功！" << std::endl;
        }
        else {
            std::cout << "没有这笔存款！\n";
        }
        p->depositSize = p->deposit.size();
    }
    else if (flag == 2) {
        std::cout << "请输入您的取款金额：" << std::endl;
        int wa = 0;
        std::cin >> wa;
        
        if (p->balance - wa < 0) {
            std::cout << "余额不足！您最多可以取" << p->balance << "元。您是否要取出这些钱？是按1，否按0。" << std::endl;
            int flag2 = 0;
            std::cin >> flag2;
            
            if (flag2 == 1) {
                p->balance = 0;
                std::cout << "取款成功！当前余额为0。" << std::endl;
            }
            else if (flag2 == 0) {
                std::cout << "取款已取消。" << std::endl;
                return;
            }
            else {
                std::cout << "请按规定输入！\n";
            }
        }
        else {
            p->balance -= wa;
            std::cout << "取款成功！当前余额: " << p->balance << std::endl;
        }
    }
    else {
        std::cout << "请按规定输入！\n";
    }
}

// 账户余额
void balanceInquiry(customerAccount p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【账户余额查询】" << std::endl << std::endl;
    
    std::cout << "您的账户余额为：" << p->balance << "元" << std::endl;
    
    if (p->deposit.size() > 0) {
        std::cout << "\n您的定期存款信息：" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        for (int i = 0; i < p->deposit.size(); i++) {
            std::cout << "第" << i + 1 << "笔存款：金额 " << p->deposit[i].depositAmount 
                      << "元，利率 " << p->deposit[i].depositRateOfInterest << std::endl;
        }
        std::cout << "--------------------------------------------------------------" << std::endl;
    }
    
    if (p->loans.size() > 0) {
        std::cout << "\n您的贷款信息：" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        for (int i = 0; i < p->loans.size(); i++) {
            std::cout << "第" << i + 1 << "笔贷款：金额 " << p->loans[i].loansAmount 
                      << "元，利率 " << p->loans[i].loansRateOfInterest << std::endl;
        }
        std::cout << "--------------------------------------------------------------" << std::endl;
    }
    
    pauseAndContinue();
}

// 贷款
void loans(customerAccount p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【贷款业务】" << std::endl << std::endl;
    
    std::cout << "请选择您的贷款方案（输入阿拉伯数字）：" << std::endl;
    std::cout << "方案1：贷款年限：1年；利息：4.25%" << std::endl;
    std::cout << "方案2：贷款年限：2年；利息：4.75%" << std::endl;
    
    int choice = 0;
    Loans t;
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            // 输入贷款金额
            std::cout << "请输入贷款金额：" << std::endl;
            std::cin >> t.loansAmount;
            t.loansRateOfInterest = 0.0425;
            p->loans.push_back(t);
            std::cout << "贷款申请成功！" << std::endl;
            break;
        case 2:
            // 输入贷款金额
            std::cout << "请输入贷款金额：" << std::endl;
            std::cin >> t.loansAmount;
            t.loansRateOfInterest = 0.0475;
            p->loans.push_back(t);
            std::cout << "贷款申请成功！" << std::endl;
            break;
        default:
            std::cout << "没有此方案！" << std::endl;
            break;
    }
    p->loansSize = p->loans.size();
}

// 计算利息
void calculateInterest(customerAccount p) {
    clearScreen();
    displayBankLogo();
    std::cout << "【利息计算】" << std::endl << std::endl;
    
    std::cout << "计算存款输入1，计算贷款输入2\n";
    int flag1 = 0;
    std::cin >> flag1;
    
    if (flag1 == 1) {
        if (p->deposit.size() == 0) {
            std::cout << "您没有任何存款！" << std::endl;
            pauseAndContinue();
            return;
        }
        
        std::cout << "您共有" << p->deposit.size() << "笔存款：" << std::endl;
        for (int i = 0; i < p->deposit.size(); i++) {
            std::cout << "第" << i + 1 << "笔存款：存款利率为：" << p->deposit[i].depositRateOfInterest;
            std::cout << " 存款数额为：" << p->deposit[i].depositAmount << std::endl;
        }
        
        std::cout << "您想要计算哪一笔？请输入阿拉伯数字\n";
        int c = 0;
        std::cin >> c;
        
        if (c > 0 && c <= p->deposit.size()) {
            double interest = p->deposit[c - 1].depositAmount * p->deposit[c - 1].depositRateOfInterest;
            std::cout << "利息为：" << interest << "元" << std::endl;
        }
        else {
            std::cout << "没有这笔存款！\n";
        }
    }
    else if (flag1 == 2) {
        if (p->loans.size() == 0) {
            std::cout << "您没有任何贷款！" << std::endl;
            pauseAndContinue();
            return;
        }
        
        std::cout << "您共有" << p->loans.size() << "笔贷款：" << std::endl;
        for (int i = 0; i < p->loans.size(); i++) {
            std::cout << "第" << i + 1 << "笔贷款：贷款利率为：" << p->loans[i].loansRateOfInterest;
            std::cout << " 贷款数额为：" << p->loans[i].loansAmount << std::endl;
        }
        
        std::cout << "您想要计算哪一笔？请输入阿拉伯数字\n";
        int c = 0;
        std::cin >> c;
        
        if (c > 0 && c <= p->loans.size()) {
            double interest = p->loans[c - 1].loansAmount * p->loans[c - 1].loansRateOfInterest;
            std::cout << "利息为：" << interest << "元" << std::endl;
        }
        else {
            std::cout << "没有这笔贷款！\n";
        }
    }
    else {
        std::cout << "输入错误！\n";
    }
    
    pauseAndContinue();
}

// 存取款业务管理总入口
void function3(customerAccount& p) {
    if (p == nullptr || p->next == nullptr) {
        clearScreen();
        displayBankLogo();
        std::cout << "【存取贷业务管理】" << std::endl << std::endl;
        std::cout << "错误：没有客户信息，请先创建客户账户！" << std::endl;
        pauseAndContinue();
        return;
    }
    
    // 选择客户
    clearScreen();
    displayBankLogo();
    std::cout << "【存取贷业务管理】" << std::endl << std::endl;
    
    std::cout << "请输入要操作的客户账号: ";
    int accountNum;
    std::cin >> accountNum;
    
    customerAccount current = p->next;
    while (current) {
        if (current->account == accountNum) {
            break;
        }
        current = current->next;
    }
    
    if (!current) {
        std::cout << "未找到该账号的客户！" << std::endl;
        pauseAndContinue();
        return;
    }
    
    int flag = 1;
    do {
        clearScreen();
        displayBankLogo();
        std::cout << "【存取贷业务管理 - 客户: " << current->name << "】" << std::endl << std::endl;
        
        std::cout << "请选择以下您想办理的业务：" << std::endl;
        std::cout << "1. 存款" << std::endl;
        std::cout << "2. 取款" << std::endl;
        std::cout << "3. 贷款" << std::endl;
        std::cout << "4. 利息计算" << std::endl;
        std::cout << "5. 账户余额" << std::endl;
        std::cout << "0. 返回主菜单" << std::endl;
        std::cout << "请输入选项(0-5): ";
        
        int choice = 0;
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                deposit(current);
                break;
            case 2:
                withdrawal(current);
                break;
            case 3:
                loans(current);
                break;
            case 4:
                calculateInterest(current);
                break;
            case 5:
                balanceInquiry(current);
                break;
            case 0:
                return;
            default:
                std::cout << "没有此业务！" << std::endl;
                break;
        }
        
        std::cout << "是否继续办理业务？继续请按1，退出请按0: ";
        std::cin >> flag;
    } while (flag); // 判断是否继续办理业务
}