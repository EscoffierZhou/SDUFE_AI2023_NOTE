#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

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
    table->R = (ElemType*)malloc(sizeof(ElemType) * (capacity + 1)); // �����һ��λ�����ڼ�����
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

// �����������ü����ڵ�˳�����(������Ԫ�ط�������ڣ�����ǰ���αȽ�,����ʱ�临�Ӷ�O(n))  
bool SeqSearch(SSTable* table, KeyType key, Infotype otherinfo) {
    table->R[0].key = key; // ���ü�����
    int i;
    for (i = table->length; table->R[i].key != key; i--);
    if (i > 0) {
        strncpy(otherinfo, table->R[i].otherinfo, sizeof(Infotype) - 1);
        otherinfo[sizeof(Infotype) - 1] = '\0'; // ȷ���ַ�����null��β  
        return true;
    }
    return false;
}

// ��������ʹ���۰���ң���һ�룬����������Ҳ��ң�С��������ң��������֣�O(log n)��
bool BinarySearch(const SSTable* table, KeyType key, Infotype otherinfo) {
    int low = 0, high = table->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (table->R[mid].key == key) {
            strncpy(otherinfo, table->R[mid].otherinfo, sizeof(Infotype) - 1);
            otherinfo[sizeof(Infotype) - 1] = '\0'; // ȷ���ַ�����null��β  
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

// �ͷž�̬������ռ�õ��ڴ�  
void FreeSSTable(SSTable* table) {
    free(table->R);
    table->R = NULL;
    table->length = 0;
    table->capacity = 0;
}

// ð������
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
            break; // ���û�з����������������Ѿ����򣬿�����ǰ��ֹ����  
        }
    }
}

// ��������
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

// �ȽϺ���������qsort����
int CompareElemType(const void* a, const void* b) {
    return ((ElemType*)a)->key - ((ElemType*)b)->key;
}

int main() {
    // ��ʼ�������������
    srand(time(NULL));

    SSTable table;
    InitSSTable(&table, 50000);

    // ����50000�����Ԫ��
    for (int i = 0; i < 50000; i++) {
        char info[100];
        snprintf(info, sizeof(info), "Info %d", i);
        InsertElem(&table, rand() % 100000, info);
    }

    Infotype info;

    // ˳����Ҳ���
    clock_t start = clock();
    SeqSearch(&table, 12345, info);
    clock_t end = clock();
    printf("SeqSearch time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // ð������
    start = clock();
    BubbleSort(table.R, table.length);
    end = clock();
    printf("BubbleSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // ��������
    // �������������
    for (int i = 0; i < 50000; i++) {
        table.R[i].key = rand() % 100000;
        snprintf(table.R[i].otherinfo, sizeof(table.R[i].otherinfo), "Info %d", i);
    }
    start = clock();
    InsertionSort(table.R, table.length);
    end = clock();
    printf("InsertionSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // ��������
    // �������������
    for (int i = 0; i < 50000; i++) {
        table.R[i].key = rand() % 100000;
        snprintf(table.R[i].otherinfo, sizeof(table.R[i].otherinfo), "Info %d", i);
    }
    start = clock();
    qsort(table.R, table.length, sizeof(ElemType), CompareElemType);
    end = clock();
    printf("QuickSort time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // �۰���Ҳ���
    start = clock();
    BinarySearch(&table, 12345, info);
    end = clock();
    printf("BinarySearch time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    FreeSSTable(&table);

    return 0;
}
