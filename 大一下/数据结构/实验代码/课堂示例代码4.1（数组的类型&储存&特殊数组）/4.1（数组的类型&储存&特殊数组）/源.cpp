#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//数组的类型定义
//一维数组可以看作是线性表，二维数组看成线性表的线性表
//定义不同方式
#define m 100
#define n 100
typedef int Elemtype;
//定义二维数组
typedef Elemtype Array2[m][n];
/*等价于
typedef Elemtype Array1[n];
typedef Array1 Array[m];
*/
// 初始化二维数组
void initializeArray(Array2 arr, int rows, int cols, Elemtype value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value;
        }
    }
}

// 给数组赋值指定位置的元素
void inputValues(Array2 arr, int rows, int cols, int row, int col, Elemtype value) {
    arr[row][col] = value;
}

// 返回指定位置的元素
Elemtype getElement(Array2 arr, int row, int col) {
    return arr[row][col];
}

int main() {
    Array2 myArray;
    int rows; // 行
    int cols; // 列

    printf("Enter the number of rows of the Array: ");
    scanf("%d", &rows);
    printf("Enter the number of columns of the Array: ");
    scanf("%d", &cols);

    // 初始化数组全部为0
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

    // 打印数组元素
    printf("Array elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", getElement(myArray, i, j));
        }
        printf("\n");
    }

    return 0;
}
