#include <iostream>
#include <cstdlib>
#define OK 1
#define ERROR -1
using namespace std;

typedef int QElemtype;
typedef int Status;

typedef struct QNode {//����һ���ṹ���ʾ�ڵ�
    QElemtype data; // ������
    QNode* next;    // ָ����
} QNode;
typedef QNode* ptr; //����ͷ�ڵ�

typedef struct {    //����һ���ṹ���ʾѭ������
    ptr front;
    ptr rear;
} LinkQueue;

/*
___________________
|__Qnode__|_Link___|//����˫�ṹ���ԭ��
_______________|___
|__s2_____|____ ___|
_______________|___
|__s3_____|________|

|


*/



Status InitQueue(LinkQueue& Q) {///��ʼ����ʽѭ�����У�ֻ��ʼ�������ڽṹ��
    Q.front = NULL;//����ָ������Ԫ�ڵ���ָ��գ�ͷ�ڵ㣩
    Q.rear = NULL;//��βָ��Ҳ����Ԫ�ڵ���ָ��գ�ͷ�ڵ㣩
    return OK;
}

bool IsEmpty(LinkQueue Q) {//�ж��Ƿ�Ϊ�յ�������������ָ���Ƿ��ǿ�
    return Q.front == NULL;
}

Status EnQueue(LinkQueue& Q, QElemtype e) {
    ptr p = (ptr)malloc(sizeof(QNode));  //��Ϊ�ո�ֻ��ʼ����ָ�����ʼ��Ԫ�ؽṹ�壬�������ڴ�ռ�
    if (!p) exit(ERROR);  //�ڴ����ʧ�ܣ��˳�����
    p->data = e;  //��Ԫ��ֵ����������
    p->next = NULL;  //��ָ�����ÿ�

    if (Q.rear == NULL) {  //�������Ϊ��
        Q.front = p;  //����ָ��ָ��ͷ�ڵ�
        Q.rear = p;  //��βָ��ָ��ͷ�ڵ�
    }
    else {
        Q.rear->next = p;  //���½ڵ����ӵ���β�ڵ�ĺ���
        Q.rear = p;  //��βָ��ָ���½ڵ�
    }
    return OK;  //����״ֵ̬1����ʾ����ɹ�
}
Status DeQueue(LinkQueue& Q, QElemtype& e) {//����ʽѭ��������ɾ��Ԫ��
    if (Q.front == NULL) return ERROR;//�������ָ��Ϊ��֤��Ŀǰû��Ԫ��
    ptr p = Q.front;//������ָ���ƶ�������ָ��λ��
    e = p->data;//������Ԫ�ص�Ԫ�ظ�ֵ���ø�e
    Q.front = Q.front->next;//���׽ڵ�����һ���ڵ���
    free(p);//�ͷ�pָ��
    return OK;
}

QElemtype GetHead(LinkQueue Q) {//�������Ԫ��
    if (Q.front != NULL) {//������鲻Ϊ��
        return Q.front->data;//�������Ԫ��
    }
    return -1; // ����Ϊ��ʱ�Ĵ�������һ��Ĭ��ֵ�����׳��쳣
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the queue:" << endl;//������Ҫ����Ԫ�صĸ���
    int num1; cin >> num1;
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the queue:" << endl;//������Ҫ�����Ԫ��
    for (int i = 1; i <= num1; i++) {
        int ele1; cin >> ele1;
        EnQueue(Q, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements you inserted are as follows:" << endl;///Ŀǰ�����²����Ԫ��
    ptr p = Q.front;
    while (p) {//�����ر�������ʽ��whileѭ����ָ��������
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the queue is:" << endl;//�������Ԫ��
    if (!IsEmpty(Q)) {
        cout << GetHead(Q) << endl;
    }
    else {
        cout << "The queue is empty." << endl;//���Ϊ�գ���û��Ԫ��
    }

    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to pop from the queue:" << endl;//�����Ҫpop����Ԫ�ظ���
    int num2; cin >> num2;
    cout << "-------------------------" << endl;
    cout << "The elements you popped from the queue are as follows:" << endl;//�����pop��Ԫ��
    for (int i = 1; i <= num2; i++) {
        int ele2;
        if (DeQueue(Q, ele2) == 1) {
            cout << ele2 << endl;
        }
        else {
            cout << "The queue is empty." << endl;
            break;
        }
    }
    cout << "-------------------------" << endl;
    cout << "The remaining elements in the queue are: " << endl;//���ʣ������Ԫ��
    p = Q.front;
    while (p) {
        cout << p->data << " " << endl;
        p = p->next;
    }
    cout << endl;
    return 0;
}