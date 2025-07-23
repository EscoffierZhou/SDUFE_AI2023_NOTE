#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 100
#define OK 1
#define ERROR -1

using namespace std;

typedef int QElemtype;
typedef int Status;
typedef struct {	//����ѭ������
	QElemtype* base;//����һ����ָ��
	int front;	//ͷָ��
	int rear;	//βָ��
}SqQueue;
/*��ѭ�������У���ָ���������ָ����е���ʼλ�ã������еĵײ�������׵�ַ��

������˵����ָ��ָ��洢����Ԫ�ص�������׵�ַ�������ڰ���ȷ��������Ԫ�ص�ʵ��λ�á�ͨ����ָ����±����ϣ����Է��ʵ������еĸ���Ԫ�ء�

ѭ�������е�����Ԫ�����������������洢�ģ��ӻ�ָ�뿪ʼ��ͨ�����������±꣬����ѭ���ر������飬ʵ�ֶ��е�ѭ�����ʡ�*/

Status Init_Queue(SqQueue& Q) {//��ʼ��ѭ������
	Q.base = new QElemtype[MAX_SIZE];//ͨ����ָ��Ϊѭ�����о�̬����ռ�
	//Q.base = (QElemtype*)malloc(MAX_SIZE * sizeof(QElemtype));
	if (!Q.base) exit(OVERFLOW);//�������ʧ����
	Q.front = Q.rear = 0;//��ʾ���еĳ�ʼ����
	return OK;//���
}

int QueueLength(SqQueue Q) {//���ض��еĳ���
	return (Q.rear - Q.front + MAX_SIZE) % MAX_SIZE;//��β�����м�ȥ���׵�����������MAXȡ����ѭ��������
}

Status In_Queue(SqQueue& Q, QElemtype e) {//����Ԫ��
	if ((Q.rear + 1) % MAX_SIZE == Q.front) return ERROR;//���ѭ������û��λ���ˣ����ش���
	Q.base[Q.rear] = e;//��e����ֵͨ����β��������ӵ�������
	Q.rear = (Q.rear + 1) % MAX_SIZE;//��βָ��������һλ
	return OK;//���
}

Status DeQueue(SqQueue& Q, QElemtype& e) {//ɾ��Ԫ��
	if (Q.front == Q.rear) return ERROR;;//���ѭ������û��Ԫ�أ����ش���
	e = Q.base[Q.front];//������ָ���Ԫ�ظ���e
	Q.front = (Q.front + 1) % MAX_SIZE;//����ָ�����һλ
	return OK;//���
}

QElemtype GetHead(SqQueue& Q) {//ȡ�����еĶ���Ԫ��
	if (Q.front != Q.rear)//�����������Ԫ��
		return Q.base[Q.front];//���ض���Ԫ��
	else {
		exit(ERROR);//�����˳�
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
	// ��������Ԫ��
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