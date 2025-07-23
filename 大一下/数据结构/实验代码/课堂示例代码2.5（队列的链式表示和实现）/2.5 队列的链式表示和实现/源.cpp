#include <iostream>
#include <cstdlib>
#define OK 1
#define ERROR -1
using namespace std;

typedef int QElemtype;
typedef int Status;

typedef struct QNode {//定义一个结构体表示节点
    QElemtype data; // 数据域
    QNode* next;    // 指针域
} QNode;
typedef QNode* ptr; //定义头节点

typedef struct {    //定义一个结构体表示循环队列
    ptr front;
    ptr rear;
} LinkQueue;

/*
___________________
|__Qnode__|_Link___|//产生双结构体的原因
_______________|___
|__s2_____|____ ___|
_______________|___
|__s3_____|________|

|


*/



Status InitQueue(LinkQueue& Q) {///初始化链式循环队列（只初始化了链节结构）
    Q.front = NULL;//队首指针在首元节点上指向空（头节点）
    Q.rear = NULL;//队尾指针也在首元节点上指向空（头节点）
    return OK;
}

bool IsEmpty(LinkQueue Q) {//判断是否为空的条件：看队首指针是否是空
    return Q.front == NULL;
}

Status EnQueue(LinkQueue& Q, QElemtype e) {
    ptr p = (ptr)malloc(sizeof(QNode));  //因为刚刚只初始化了指针域初始化元素结构体，并分配内存空间
    if (!p) exit(ERROR);  //内存分配失败，退出程序
    p->data = e;  //将元素值赋给数据域
    p->next = NULL;  //将指针域置空

    if (Q.rear == NULL) {  //如果队列为空
        Q.front = p;  //队首指针指向头节点
        Q.rear = p;  //队尾指针指向头节点
    }
    else {
        Q.rear->next = p;  //将新节点连接到队尾节点的后面
        Q.rear = p;  //队尾指针指向新节点
    }
    return OK;  //返回状态值1，表示插入成功
}
Status DeQueue(LinkQueue& Q, QElemtype& e) {//从链式循环队列中删除元素
    if (Q.front == NULL) return ERROR;//如果队首指针为空证明目前没有元素
    ptr p = Q.front;//定义新指针移动到队首指针位置
    e = p->data;//将队首元素的元素赋值引用给e
    Q.front = Q.front->next;//队首节点向下一个节点走
    free(p);//释放p指针
    return OK;
}

QElemtype GetHead(LinkQueue Q) {//输出队首元素
    if (Q.front != NULL) {//如果队伍不为空
        return Q.front->data;//输出队首元素
    }
    return -1; // 队列为空时的处理，返回一个默认值或者抛出异常
}

int main() {
    LinkQueue Q;
    InitQueue(Q);
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the queue:" << endl;//输入想要输入元素的个数
    int num1; cin >> num1;
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the queue:" << endl;//输入想要插入的元素
    for (int i = 1; i <= num1; i++) {
        int ele1; cin >> ele1;
        EnQueue(Q, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements you inserted are as follows:" << endl;///目前所有新插入的元素
    ptr p = Q.front;
    while (p) {//链表特别的输出方式：while循环和指针控制输出
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the queue is:" << endl;//输出队首元素
    if (!IsEmpty(Q)) {
        cout << GetHead(Q) << endl;
    }
    else {
        cout << "The queue is empty." << endl;//如果为空，即没有元素
    }

    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to pop from the queue:" << endl;//输出想要pop掉的元素个数
    int num2; cin >> num2;
    cout << "-------------------------" << endl;
    cout << "The elements you popped from the queue are as follows:" << endl;//输出被pop的元素
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
    cout << "The remaining elements in the queue are: " << endl;//输出剩下所有元素
    p = Q.front;
    while (p) {
        cout << p->data << " " << endl;
        p = p->next;
    }
    cout << endl;
    return 0;
}