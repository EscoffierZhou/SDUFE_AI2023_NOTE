#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 100
#define OK 1
#define ERROR -1

using namespace std;

typedef int QElemtype;
typedef int Status;
typedef struct {	//定义循环队列
	QElemtype* base;//定义一个基指针
	int front;	//头指针
	int rear;	//尾指针
}SqQueue;
/*在循环队列中，基指针的作用是指向队列的起始位置，即队列的底层数组的首地址。

具体来说，基指针指向存储队列元素的数组的首地址，它用于帮助确定队列中元素的实际位置。通过基指针和下标的组合，可以访问到队列中的各个元素。

循环队列中的数据元素在数组中是连续存储的，从基指针开始，通过不断增加下标，可以循环地遍历数组，实现队列的循环性质。*/

Status Init_Queue(SqQueue& Q) {//初始化循环队列
	Q.base = new QElemtype[MAX_SIZE];//通过基指针为循环队列静态分配空间
	//Q.base = (QElemtype*)malloc(MAX_SIZE * sizeof(QElemtype));
	if (!Q.base) exit(OVERFLOW);//如果分配失败了
	Q.front = Q.rear = 0;//表示队列的初始索引
	return OK;//完成
}

int QueueLength(SqQueue Q) {//返回队列的长度
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;//队尾的序列减去队首的索引（加上MAX取余是循环操作）
}

Status In_Queue(SqQueue& Q, QElemtype e) {//插入元素
	if ((Q.rear + 1) % MAX_SIZE == Q.front) return ERROR;//如果循环队列没有位置了，返回错误
	Q.base[Q.rear] = e;//将e的数值通过队尾的索引添加到队列中
	Q.rear = (Q.rear + 1) % MAX_SIZE;//队尾指针往后走一位
	return OK;//完成
}

Status DeQueue(SqQueue& Q, QElemtype& e) {//删除元素
	if (Q.front == Q.rear) return ERROR;;//如果循环队列没有元素，返回错误
	e = Q.base[Q.front];//将队首指针的元素赋给e
	Q.front = (Q.front + 1) % MAX_SIZE;//队首指针向后一位
	return OK;//完成
}

QElemtype GetHead(SqQueue& Q) {//取出队列的队首元素
	if (Q.front != Q.rear)//如果队里面有元素
		return Q.base[Q.front];//返回队首元素
	else {
		exit(ERROR);//否则退出
	}
}

int main() {
	SqQueue q1;
	Init_Queue(q1);
	cout << "-------------------------" << endl;
	cout << "Insert the number of elements you want to push into the queue:" << endl;
	int num1; cin >> num1;
	cout << "-------------------------" << endl;
	cout << "Insert the elements you want to push into the queue:" << endl;
	for (int i = 1; i <= num1; i++) {
		int ele1; cin >> ele1;
		In_Queue(q1, ele1);
	}
	cout << "-------------------------" << endl;
	cout << "The elements you inserted are as follows:" << endl;
	// 输出插入的元素
	int front = q1.front;
	int rear = q1.rear;
	while (front != rear) {
		cout << q1.base[front] << " ";
		front = (front + 1) % MAX_SIZE;
	}
	cout << endl;

	cout << "-------------------------" << endl;
	cout << "The top element of the queue is :" << endl;
	cout << GetHead(q1) << endl;

	cout << "-------------------------" << endl;
	cout << "Insert the number of elements you want to pop from the queue:" << endl;
	int num2; cin >> num2;
	cout << "-------------------------" << endl;
	cout << "The elements you popped from the queue are as follows:" << endl;
	for (int i = 1; i <= num2+1; i++) {
		int ele2;
		if (DeQueue(q1, ele2) == OK) {
			cout << ele2 << endl;
		}
	}
	return 0;
}