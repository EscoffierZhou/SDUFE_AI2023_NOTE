#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//��������Ͷ���
//һά������Կ��������Ա���ά���鿴�����Ա�����Ա�
//���岻ͬ��ʽ
#define m 100
#define n 100
typedef int Elemtype;
//�����ά����
typedef Elemtype Array2[m][n];
/*�ȼ���
typedef Elemtype Array1[n];
typedef Array1 Array[m];
*/
// ��ʼ����ά����
void initializeArray(Array2 arr, int rows, int cols, Elemtype value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
        }
    }
}

// �����鸳ֵָ��λ�õ�Ԫ��
void inputValues(Array2 arr, int rows, int cols, int row, int col, Elemtype value) {
    arr[row][col] = value;
}

// ����ָ��λ�õ�Ԫ��
Elemtype getElement(Array2 arr, int row, int col) {
    return arr[row][col];
}

int main() {
    Array2 myArray;
    int rows; // ��
    int cols; // ��

    printf("Enter the number of rows of the Array: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the Array: ");
    scanf("%d", &cols);

    // ��ʼ������ȫ��Ϊ0
    initializeArray(myArray, rows, cols, 0);

    printf("How many elements would you like to insert: ");
    int num;
    scanf("%d", &num);

    int cnt = 0;
    while (cnt < num) {
        int value;
        printf("Enter value %d: ", cnt + 1);
        scanf("%d", &value);

        int row, col;
        printf("Enter position (row col) to insert: ");
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            inputValues(myArray, rows, cols, row, col, value);
            cnt++;
        }
        else {
            printf("Invalid position! Please enter a valid position.\n");
        }
    }

    // ��ӡ����Ԫ��
    printf("Array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", getElement(myArray, i, j));
        }
        printf("\n");
    }

    return 0;
}
