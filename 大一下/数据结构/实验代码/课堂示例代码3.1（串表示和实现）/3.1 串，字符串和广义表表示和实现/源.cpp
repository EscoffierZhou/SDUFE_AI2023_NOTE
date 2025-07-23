#include <iostream>
#include <cstring>
#define MAX_SIZE 100
#define CHUNK_SIZE 20
#define ERROR -1
#define OK 1

typedef struct {//定义Sstring（字符数组）优点：短字符串便于维护
    char ch[MAX_SIZE + 1];
    int length;
} Sstring;

typedef struct chunk {//定义chunk指针结构体 优点：chunk辅助结构体助阵，长字符串优势
    char chunk[CHUNK_SIZE];
    struct chunk* next;
} chunk;

typedef struct {//定义Lstring
    chunk* head, * tail;//定义双指针指向chunk
    int length;//定义长度，是若干个chunk结构体的长度
} LString;

void Init_Sstring(Sstring& str, const char* input) {//创建Sstring
    int len = strlen(input);//根据输入长度开辟空间
    if (len > MAX_SIZE)
        len = MAX_SIZE;
    strncpy(str.ch, input, len);
    str.ch[len] = '\0';//strncpy容易玩脱，需要NULL结尾
    str.length = len;//记录Sstring的长度len
}

void modifySString(Sstring& str, const char* newStr) {//修改Sstring（直接copy覆盖）
    int len = strlen(newStr);
    if (len > MAX_SIZE)
        len = MAX_SIZE;
    strncpy(str.ch, newStr, len);
    str.ch[len] = '\0';
    str.length = len;
}

void deleteSString(Sstring& str) {//重置长度和首位元素即可清零
    str.length = 0;
    str.ch[0] = '\0';
}

int findSubstringSString(const Sstring& str, const char* subStr) {//寻找子字符串
    int subLen = strlen(subStr);//首先还是定义长度便于查找
    int strLen = str.length;

    for (int i = 0; i <= strLen - subLen; ++i) {//在字符串中找从0到len-substr的长度
        int j;
        for (j = 0; j < subLen; ++j) {//按照substr的长度找
            if (str.ch[i + j] != subStr[j])//如果存在则break
                break;
        }
        if (j == subLen)
            return i;
    }
    return ERROR;
}
//以下是Lstring的代码部分

void Init_Lstring(LString& lstr, const char* input) {
    // 初始化Lstring
    int len = strlen(input); // 记录输入字符串的长度

    // 创建头结点
    lstr.head = new chunk;
    lstr.tail = lstr.head;
    lstr.length = len;
//分割字符串并且组装成链表
    int remaining = len;
    const char* ptr = input;//修改为常量避免改动

    while (remaining > 0) {
        int chunkLen = remaining > CHUNK_SIZE ? CHUNK_SIZE : remaining;//按照长度为chunklen进行分块

        strncpy(lstr.tail->chunk, ptr, chunkLen); //将长度为 chunkLen 的字符串从 ptr 复制到所指向的目标字符数组中。
   
        lstr.tail->chunk[chunkLen] = '\0';//在strncpy后面都要手动添加 null 终止符
        remaining -= chunkLen; //更新剩余字符数
        ptr += chunkLen;//更新源字符串指针的位置。

        if (remaining > 0) {   // 创建并连接新的块
            lstr.tail->next = new chunk;
            lstr.tail = lstr.tail->next;
        }
    }
    // 设置尾结点的下一个指针为空
    lstr.tail->next = nullptr;
}

void modifyLString(LString& lstr, const char* newStr) {
    chunk* current = lstr.head; // 当前处理的块
    int len = strlen(newStr); // 新字符串的长度
    lstr.length = len; // 更新LString的长度

    int remaining = len; // 剩余字符数
    const char* ptr = newStr; // 源字符串指针，指向newStr的初始位置
    while (remaining > 0) {
        int chunkLen = remaining > CHUNK_SIZE ? CHUNK_SIZE : remaining; // 当前块的长度，最多为CHUNK_SIZE
        strncpy(current->chunk, ptr, chunkLen); // 将源字符串的一部分内容复制到当前块中
        current->chunk[chunkLen] = '\0'; // 手动添加 null 终止符
        remaining -= chunkLen; // 更新剩余字符数
        ptr += chunkLen; // 更新源字符串指针的位置

        if (remaining > 0) {
            if (current->next == nullptr) { // 如果当前块的下一个块为空
                current->next = new chunk; // 创建新的块
                lstr.tail = current->next; // 更新链表的尾结点
            }
            current = current->next; // 移动到下一个块
        }
    }
    if (current->next != nullptr) { // 如果尾结点的下一个块不为空
        chunk* temp = current->next; // 临时指针指向尾结点的下一个块
        current->next = nullptr; // 尾结点的下一个指针设为空
        delete temp; // 释放尾结点的下一个块的内存
    }
}

void deleteLString(LString& lstr) {
    chunk* current = lstr.head;
    while (current != nullptr) {
        chunk* temp = current;
        current = current->next;
        delete temp;
    }
    lstr.head = nullptr;
    lstr.tail = nullptr;
    lstr.length = 0;
}

int findSubstringLString(const LString& lstr, const char* subStr) {
    int subLen = strlen(subStr);
    chunk* current = lstr.head;
    int index = 0;

    while (current != nullptr) {
        int chunkLen = strlen(current->chunk);
        for (int i = 0; i <= chunkLen - subLen; ++i) {
            int j;
            for (j = 0; j < subLen; ++j) {
                if (current->chunk[i + j] != subStr[j])
                    break;
            }
            if (j == subLen)
                return index + i;
        }
        index += chunkLen;
        current = current->next;
    }
    return -1;
}

int main() {
    Sstring sstr;
    LString lstr;
    char input[MAX_SIZE + 1];

    std::cout << "Enter a string: ";
    std::cin.getline(input, MAX_SIZE + 1);

    Init_Sstring(sstr, input);
    Init_Lstring(lstr, input);
}
   