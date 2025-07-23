#include "utils.h"

void displayBankLogo() {
    std::cout << "\n";
    std::cout << "  ██████╗  █████╗ ███╗   ██╗██╗  ██╗    ███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗\n";
    std::cout << "  ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝    ██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║\n";
    std::cout << "  ██████╔╝███████║██╔██╗ ██║█████╔╝     ███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║\n";
    std::cout << "  ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗     ╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║\n";
    std::cout << "  ██████╔╝██║  ██║██║ ╚████║██║  ██╗    ███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║\n";
    std::cout << "  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝    ╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝\n";
    std::cout << "================================================================================\n\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseAndContinue() {
    std::cout << "\n按回车键继续...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int safeInputInteger() {
    int input;
    while (!(std::cin >> input)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入无效，请输入一个数字: ";
    }
    return input;
}