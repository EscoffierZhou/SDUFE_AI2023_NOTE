#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
    table->R = (ElemType*)malloc(sizeof(ElemType) * (capacity + 1)); // 多分配一个位置用于监视哨
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

// 无序数列设置监视哨的顺序查找(把所找元素放入监视哨，后往前依次比较,所以时间复杂度O(n))  
bool SeqSearch(SSTable* table, KeyType key, Infotype otherinfo) {
    table->R[0].key = key; // 设置监视哨
    int i;
    for (i = table->length; table->R[i].key != key; i--);
    if (i > 0) {
        strncpy(otherinfo, table->R[i].otherinfo, sizeof(Infotype) - 1);
        otherinfo[sizeof(Infotype) - 1] = '\0'; // 确保字符串以null结尾  
        return true;
    }
    return false;
}

// 有序数列使用折半查找，分一半，如果大于向右查找，小于向左查找，继续二分（O(log n)）
bool BinarySearch(const SSTable* table, KeyType key, Infotype otherinfo) {
    int low = 0, high = table->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (table->R[mid].key == key) {
            strncpy(otherinfo, table->R[mid].otherinfo, sizeof(Infotype) - 1);
            otherinfo[sizeof(Infotype) - 1] = '\0'; // 确保字符串以null结尾  
            return true;
        }
        else if (table->R[mid].key < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}

// 释放静态搜索表占用的内存  
void FreeSSTable(SSTable* table) {
    free(table->R);
    table->R = NULL;
    table->length = 0;
    table->capacity = 0;
}

// 冒泡排序
void BubbleSort(ElemType* array, int length) {
    bool swapped;
    for (int i = 0; i < length - 1; i++) {
        swapped = false;
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j].key > array[j + 1].key) {
                ElemType temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break; // 如果没有发生交换，则数组已经有序，可以提前终止排序  
        }
    }
}

// 插入排序
void InsertionSort(ElemType* array, int length) {
    for (int i = 1; i < length; i++) {
        ElemType key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j].key > key.key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// 比较函数，用于qsort排序
int CompareElemType(const void* a, const void* b) {
    return ((ElemType*)a)->key - ((ElemType*)b)->key;
}

int main() {
    // 初始化随机数生成器
    srand(time(NULL));

    SSTable table;
    InitSSTable(&table, 50000);

    // 插入50000个随机元素
    for (int i = 0; i < 50000; i++) {
        char info[100];
        snprintf(info, sizeof(info), "Info %d", i);
        InsertElem(&table, rand() % 100000, info);
    }

    Infotype info;

    // 顺序查找测试
    clock_t start = clock();
    SeqSearch(&table, 12345, info);
    clock_t end = clock();
    printf("SeqSearch time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 冒泡排序
    start = clock();
    BubbleSort(table.R, table.length);
    end = clock();
    printf("BubbleSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 插入排序
    // 重新生成随机数
    for (int i = 0; i < 50000; i++) {
        table.R[i].key = rand() % 100000;
        snprintf(table.R[i].otherinfo, sizeof(table.R[i].otherinfo), "Info %d", i);
    }
    start = clock();
    InsertionSort(table.R, table.length);
    end = clock();
    printf("InsertionSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 快速排序
    // 重新生成随机数
    for (int i = 0; i < 50000; i++) {
        table.R[i].key = rand() % 100000;
        snprintf(table.R[i].otherinfo, sizeof(table.R[i].otherinfo), "Info %d", i);
    }
    start = clock();
    qsort(table.R, table.length, sizeof(ElemType), CompareElemType);
    end = clock();
    printf("QuickSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 折半查找测试
    start = clock();
    BinarySearch(&table, 12345, info);
    end = clock();
    printf("BinarySearch time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    FreeSSTable(&table);

    return 0;
}
