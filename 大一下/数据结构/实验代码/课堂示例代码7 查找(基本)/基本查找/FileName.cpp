#include <iostream>  
#include <vector>  
#include <cmath>  
#include <algorithm>  
#include <stdlib.h>  
#include <stdbool.h>  

// ��������Ͷ��壬����ʵ����������޸�  
typedef int KeyType;
typedef char Infotype[100]; // ����������Ϣ���ַ�������  

// Ԫ�����Ͷ���  
typedef struct {
    KeyType key;
    Infotype otherinfo;
} ElemType;

// ��̬���������Ͷ���  
typedef struct {
    ElemType* R;
    int length;
    int capacity; // ��������ֶΣ����ڼ�¼����Ĵ�С  
} SSTable;

// ��ʼ����̬������  
void InitSSTable(SSTable* table, int capacity) {
    table->capacity = capacity;
    table->R = (ElemType*)malloc(sizeof(ElemType) * capacity);
    if (table->R == NULL) {
        exit(EXIT_FAILURE); // �����ڴ�ʧ��ʱ�˳�����  
    }
    table->length = 0;
}

// ����Ԫ�ص���̬��������ʵ�֣�������������ظ�����  
bool InsertElem(SSTable* table, KeyType key, const Infotype otherinfo) {
    if (table->length >= table->capacity) {
        return false; // ���������޷�����  
    }
    table->R[table->length].key = key;
    strncpy(table->R[table->length].otherinfo, otherinfo, sizeof(Infotype) - 1);
    table->R[table->length].otherinfo[sizeof(Infotype) - 1] = '\0'; // ȷ���ַ�����null��β  
    table->length++;
    return true;
}

// �ھ�̬������������Ԫ��  
bool SearchElem(const SSTable* table, KeyType key, Infotype otherinfo) {
    for (int i = 0; i < table->length; i++) {
        if (table->R[i].key == key) {
            strncpy(otherinfo, table->R[i].otherinfo, sizeof(Infotype) - 1);
            otherinfo[sizeof(Infotype) - 1] = '\0'; // ȷ���ַ�����null��β  
            return true;
        }
    }
    return false; // δ�ҵ�Ԫ��  
}

// �ͷž�̬������ռ�õ��ڴ�  
void FreeSSTable(SSTable* table) {
    free(table->R);
    table->R = NULL;
    table->length = 0;
    table->capacity = 0;
}

// �ھ�̬�������а��ؼ��ֲ���Ԫ��  
ElemType* SearchByKey(const SSTable* table, KeyType key) {
    for (int i = 0; i < table->length; i++) {
        if (table->R[i].key == key) {
            return (ElemType*)&table->R[i]; // �����ҵ���Ԫ�ص�ָ��  
        }
    }
    return NULL; // δ�ҵ�Ԫ���򷵻�NULL  
}

// �ھ�̬��������˳�����Ԫ�أ�����������Ϣ������������  
ElemType* SequentialSearch(const SSTable* table, const Infotype otherinfo) {
    for (int i = 0; i < table->length; i++) {
        if (strcmp(table->R[i].otherinfo, otherinfo) == 0) {
            return (ElemType*)&table->R[i]; // �����ҵ���Ԫ�ص�ָ��  
        }
    }
    return NULL; // δ�ҵ�Ԫ���򷵻�NULL  
}

// ������̬�������ж��ֲ���Ԫ��  
ElemType* BinarySearch(const SSTable* table, KeyType key) {
    int low = 0, high = table->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (table->R[mid].key == key) {
            return (ElemType*)&table->R[mid]; // �����ҵ���Ԫ�ص�ָ��  
        }
        else if (table->R[mid].key < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return NULL; // δ�ҵ�Ԫ���򷵻�NULL  
}

int main() {
    SSTable myTable;
    InitSSTable(&myTable, 10); // ��ʼ������Ϊ10�ľ�̬������  

    // ����Ԫ��ʾ��  
    InsertElem(&myTable, 1, "Info for key 1");
    InsertElem(&myTable, 2, "Info for key 2");
    InsertElem(&myTable, 3, "Info for key 3");

    // ����Ԫ��ʾ��  
    Infotype foundInfo;
    if (SearchElem(&myTable, 2, foundInfo)) {
        printf("Found info for key 2: %s\n", foundInfo);
    }
    else {
        printf("Key 2 not found\n");
    }

    // �ͷ���Դ  
    FreeSSTable(&myTable);
    return 0;
}



/*
// ˳�����  
// ˳�������һ��������Ĳ��ҷ����������б�ĵ�һ��Ԫ�ؿ�ʼ������Ƚϣ�ֱ���ҵ�Ŀ��Ԫ�ػ�����������б�  
int sequentialSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // �ҵ�Ŀ�꣬��������  
        }
    }
    return -1; // δ�ҵ�Ŀ�꣬����-1  
}

// �۰���ң����ֲ��ң�  
// ���ֲ�����һ�������������в����ض�Ԫ�ص������㷨��ÿ�αȽ϶�ʹ������Χ���롣  
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid; // �ҵ�Ŀ�꣬��������  
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // δ�ҵ�Ŀ�꣬����-1  
}

// �ֿ���ң�����˳����ң�  
// �ֿ���ҽ����˳����ҺͶ��ֲ��ҵ��ŵ㣬�������Ϊ���ɿ飬����Ԫ�����򣬿�ͷԪ������  
int blockSearch(const std::vector<int>& arr, const std::vector<int>& blockHeads, int blockSize, int target) {
    int blockIndex = -1;
    // ����ȷ��Ŀ����ܴ��ڵĿ�  
    for (int i = 0; i < blockHeads.size(); ++i) {
        if (target < blockHeads[i]) {
            blockIndex = i - 1;
            break;
        }
    }
    if (blockIndex == -1) {
        blockIndex = blockHeads.size() - 1;
    }
    // ��ȷ���Ŀ��ڽ���˳�����  
    int startIndex = blockIndex * blockSize;
    for (int i = startIndex; i < startIndex + blockSize && i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // �ҵ�Ŀ�꣬��������  
        }
    }
    return -1; // δ�ҵ�Ŀ�꣬����-1  
}

int main() {
    std::vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    std::vector<int> blockHeads = { 1, 7, 13, 19 }; // ����ÿ���СΪ3�����һ�����С��3��  
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