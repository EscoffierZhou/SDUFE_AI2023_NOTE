#include <iostream>  
#include <vector>  
#include <cmath>  
#include <algorithm>  
#include <stdlib.h>  
#include <stdbool.h>  

// 假设的类型定义，根据实际需求进行修改  
typedef int KeyType;
typedef char Infotype[100]; // 假设其他信息是字符串类型  

// 元素类型定义  
typedef struct {
    KeyType key;
    Infotype otherinfo;
} ElemType;

// 静态搜索表类型定义  
typedef struct {
    ElemType* R;
    int length;
    int capacity; // 添加容量字段，用于记录数组的大小  
} SSTable;

// 初始化静态搜索表  
void InitSSTable(SSTable* table, int capacity) {
    table->capacity = capacity;
    table->R = (ElemType*)malloc(sizeof(ElemType) * capacity);
    if (table->R == NULL) {
        exit(EXIT_FAILURE); // 分配内存失败时退出程序  
    }
    table->length = 0;
}

// 插入元素到静态搜索表（简单实现，不考虑排序和重复键）  
bool InsertElem(SSTable* table, KeyType key, const Infotype otherinfo) {
    if (table->length >= table->capacity) {
        return false; // 表已满，无法插入  
    }
    table->R[table->length].key = key;
    strncpy(table->R[table->length].otherinfo, otherinfo, sizeof(Infotype) - 1);
    table->R[table->length].otherinfo[sizeof(Infotype) - 1] = '\0'; // 确保字符串以null结尾  
    table->length++;
    return true;
}

// 在静态搜索表中搜索元素  
bool SearchElem(const SSTable* table, KeyType key, Infotype otherinfo) {
    for (int i = 0; i < table->length; i++) {
        if (table->R[i].key == key) {
            strncpy(otherinfo, table->R[i].otherinfo, sizeof(Infotype) - 1);
            otherinfo[sizeof(Infotype) - 1] = '\0'; // 确保字符串以null结尾  
            return true;
        }
    }
    return false; // 未找到元素  
}

// 释放静态搜索表占用的内存  
void FreeSSTable(SSTable* table) {
    free(table->R);
    table->R = NULL;
    table->length = 0;
    table->capacity = 0;
}

// 在静态搜索表中按关键字查找元素  
ElemType* SearchByKey(const SSTable* table, KeyType key) {
    for (int i = 0; i < table->length; i++) {
        if (table->R[i].key == key) {
            return (ElemType*)&table->R[i]; // 返回找到的元素的指针  
        }
    }
    return NULL; // 未找到元素则返回NULL  
}

// 在静态搜索表中顺序查找元素（根据其他信息或其他条件）  
ElemType* SequentialSearch(const SSTable* table, const Infotype otherinfo) {
    for (int i = 0; i < table->length; i++) {
        if (strcmp(table->R[i].otherinfo, otherinfo) == 0) {
            return (ElemType*)&table->R[i]; // 返回找到的元素的指针  
        }
    }
    return NULL; // 未找到元素则返回NULL  
}

// 在有序静态搜索表中二分查找元素  
ElemType* BinarySearch(const SSTable* table, KeyType key) {
    int low = 0, high = table->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (table->R[mid].key == key) {
            return (ElemType*)&table->R[mid]; // 返回找到的元素的指针  
        }
        else if (table->R[mid].key < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return NULL; // 未找到元素则返回NULL  
}

int main() {
    SSTable myTable;
    InitSSTable(&myTable, 10); // 初始化容量为10的静态搜索表  

    // 插入元素示例  
    InsertElem(&myTable, 1, "Info for key 1");
    InsertElem(&myTable, 2, "Info for key 2");
    InsertElem(&myTable, 3, "Info for key 3");

    // 搜索元素示例  
    Infotype foundInfo;
    if (SearchElem(&myTable, 2, foundInfo)) {
        printf("Found info for key 2: %s\n", foundInfo);
    }
    else {
        printf("Key 2 not found\n");
    }

    // 释放资源  
    FreeSSTable(&myTable);
    return 0;
}



/*
// 顺序查找  
// 顺序查找是一种最基本的查找方法，它从列表的第一个元素开始，逐个比较，直到找到目标元素或遍历完整个列表。  
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // 找到目标，返回索引  
        }
    }
    return -1; // 未找到目标，返回-1  
}

// 折半查找（二分查找）  
// 二分查找是一种在有序数组中查找特定元素的搜索算法。每次比较都使搜索范围减半。  
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // 找到目标，返回索引  
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // 未找到目标，返回-1  
}

// 分块查找（索引顺序查找）  
// 分块查找结合了顺序查找和二分查找的优点，将数组分为若干块，块内元素无序，块头元素有序。  
int blockSearch(const std::vector<int>& arr, const std::vector<int>& blockHeads, int blockSize, int target) {
    int blockIndex = -1;
    // 首先确定目标可能存在的块  
    for (int i = 0; i < blockHeads.size(); ++i) {
        if (target < blockHeads[i]) {
            blockIndex = i - 1;
            break;
        }
    }
    if (blockIndex == -1) {
        blockIndex = blockHeads.size() - 1;
    }
    // 在确定的块内进行顺序查找  
    int startIndex = blockIndex * blockSize;
    for (int i = startIndex; i < startIndex + blockSize && i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // 找到目标，返回索引  
        }
    }
    return -1; // 未找到目标，返回-1  
}

int main() {
    std::vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    std::vector<int> blockHeads = { 1, 7, 13, 19 }; // 假设每块大小为3（最后一块可能小于3）  
    int blockSize = 3;
    int target = 13;

    int sequentialIndex = sequentialSearch(arr, target);
    std::cout << "Sequential Search Index: " << sequentialIndex << std::endl;

    int binaryIndex = binarySearch(arr, target);
    std::cout << "Binary Search Index: " << binaryIndex << std::endl;

    int blockIndex = blockSearch(arr, blockHeads, blockSize, target);
    std::cout << "Block Search Index: " << blockIndex << std::endl;

    return 0;
}*/