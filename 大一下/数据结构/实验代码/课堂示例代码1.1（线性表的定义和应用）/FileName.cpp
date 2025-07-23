#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
#define TRUE 1
#define False 0
#define OK 1
#define	ERROR 0
#define overflow -2
#define LIST_INIT_SIZE 100	//线性表储存空间
#define LISTINCREMENT 10	//线性表增长空间
typedef int Status;
typedef int ElemType;
typedef struct				//线性表的储存结构
{
	ElemType* elem;		//一维数组，采用动态分配
	int length;			//线性表的实际长度
	int listsize;		//记录当前分配的数组大小，方便加长度而不是重新分配内存大小
}SqList;

Status InitList_Sq(SqList &L) {	//顺序表的初始化
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));	//通过Elemtype*为struct分配大小为INIT_SIZE的储存空间
	if (!L.elem)return(overflow);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}//InitList_Sq

Status Clearlist_Sq(SqList &L) {	//顺序表的制空
	L.length = 0;
	return OK;
}//ClearList_Sq;

Status ListInsert_Sq(SqList& L,int i,ElemType e) {	//在线性表L的第i个元素前插入元素e，其中i的取值为1~sizeof(L+1)
	ElemType* p, * q;
	if (i<1 || i>L.length + 1)return ERROR;			//插入位置不合法
	q = &(L.elem[i - 1]);							//q指示插入位置
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
	*(p + 1) = *p;//插入位置及之后的元素右移
	*q = e;
	++L.length;
	return OK;
}//ListInsert_sq

Status ListDelete_Sq(SqList& L, int i, ElemType& e) { //删除线性表L的第i个元素，并用参数e返回被删元素的值，其中i的取值为1~L.length
	ElemType* p, * q;
	if ((i < 1) || (i > L.length))return ERROR;
	p = &(L.elem[i - 1]);	//p为被删元素的位置
	e = *p;					//被删元素赋值给e
	q = L.elem + L.length - 1;//表示元素的位置
	for (++p; p <= q; ++p)*(p - 1) = *p;
	--L.length;
	return OK;
}//ListInsert_Sq

Status ListShow_Sq(SqList& L) {//输出线性表的每一个元素
	printf("-------------------------\n");
	printf("The sorted list is:\n");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
		printf("\n");
	}
	printf("-------------------------\n");
	return OK;
}//ListShow_Sq

Status ListSort_Sq(SqList& L) {
	int i, j, k;    // 三个中间变量i和k是位置索引
	ElemType t;      // 临时变量，用于交换元素值

	for (i = 0; i < L.length - 1; i++) {
		k = i;    // 初始化 k 为当前轮次的最小元素索引

		// 在未排序部分中找到最小元素的索引
		for (j = i + 1; j < L.length; j++) {
			if (L.elem[k] > L.elem[j]) {
				k = j;    // 更新最小元素位置
			}
		}

		// 如果最小元素不在当前位置（找到了最小值），则进行交换
		if (k != i) {
			t = L.elem[i];
			L.elem[i] = L.elem[k];
			L.elem[k] = t;
		}
	}

	return OK;
}

void MergeList(SqList& La, SqList& Lb, SqList& Lc) {
	int i = 0, j = 0, k = 0; // 初始化索引 i、j、k 分别为 0
	while (i < La.length && j < Lb.length) { // 循环直到 La 或 Lb 中的元素全部取完
		if (La.elem[i] <= Lb.elem[j]) { // 如果 La 中的元素较小或相等
			ListInsert_Sq(Lc, ++k, La.elem[i]); // 将 La 中的元素插入到 Lc 中
			++i; // 更新 La 索引
		}
		else { // 如果 Lb 中的元素较小
			ListInsert_Sq(Lc, ++k, Lb.elem[j]); // 将 Lb 中的元素插入到 Lc 中
			++j; // 更新 Lb 索引
		}
	}
	while (i < La.length) { // 处理剩余的 La 元素
		ListInsert_Sq(Lc, ++k, La.elem[i]);
		++i;
	}
	while (j < Lb.length) { // 处理剩余的 Lb 元素
		ListInsert_Sq(Lc, ++k, Lb.elem[j]);
		++j;
	}
}

Status DestroyList_Sq(SqList& L) {	//顺序表的销毁
	if (L.elem)
		 free(L.elem);
	L.elem = NULL;
	return OK;
}//DestroyList_Sq


int main() {
	SqList La, Lb, Lc;
	int i;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);

	// 向 La 中插入元素
	int n1,ele1;
	cout << "-------------------------" << endl;
	cout << "Input the number of the elements in the la" << endl;
	cin >> n1;
	cout << "-------------------------" << endl;
	cout << "Input the elements of the la" << endl;
	for (i = 1; i <= n1; i++) {
		scanf_s("%d", &ele1);
		ListInsert_Sq(La, i, ele1);
	}
	cout << "-------------------------" << endl;
	ListShow_Sq(La);  // 输出 La 的元素
	cout << "-------------------------" << endl;



	// 向 Lb 中插入元素
	int n2,ele2;
	cout << "-------------------------" << endl;
	cout << "Input the number of the elements in thr lb" << endl;
	cin >> n2;
	cout << "-------------------------" << endl;
	cout << "Input the elements of the lb" << endl;

	for (i = 1; i <= n2; i++) {
		scanf_s("%d", &ele2);
		ListInsert_Sq(Lb, i, ele2);
	}
	cout << "-------------------------" << endl;
	printf("Lb: ");
	ListShow_Sq(Lb);  // 输出 Lb 的元素
	cout << "-------------------------" << endl;

	// 合并 La 和 Lb，并将结果存入 Lc
	cout << "--------------------------" << endl;
	cout << "The merged list lc:\n" << endl;
	MergeList(La, Lb, Lc);
	ListShow_Sq(Lc);  // 输出 Lc 的元素

	// 对 Lc 进行排序
	cout << "-------------------------" << endl;
	ListSort_Sq(Lc);
	printf("Lc (sorted): ");
	ListShow_Sq(Lc);  // 输出排序后的 Lc 的元素
	cout << "-------------------------" << endl;

	// 删除 Lc 中的第一个元素
	ElemType e;
	ListDelete_Sq(Lc, 1, e);
	printf("Deleted element from Lc: %d\n", e);

	printf("Lc: ");
	ListShow_Sq(Lc);  // 输出删除元素后的 Lc 的元素
	cout << "-------------------------" << endl;
	DestroyList_Sq(La);
	DestroyList_Sq(Lb);
	DestroyList_Sq(Lc);

	return 0;
}