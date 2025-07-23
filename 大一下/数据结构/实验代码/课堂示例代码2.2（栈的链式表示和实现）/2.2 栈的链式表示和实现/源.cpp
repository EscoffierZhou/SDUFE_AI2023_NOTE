#include <iostream>
#include <cstdlib>
using namespace std;
#define Status int
#define OK 0
#define ERROR -2
typedef int s_Elemtype;
typedef struct StackNode {//��ʼ�����ڵĽṹ��
    s_Elemtype data;//����������
    struct StackNode* next;//����ָ����
} StackNode;//����������

typedef struct {
    StackNode* top;//�����ջ��Ҫ˫ָ��ͬʱ̽��
} LinkStack;

Status Init_Stack(LinkStack& s) {//��ʼ������
    s.top = NULL;//topָ��ָ��ջ�����һ��NULLָ�루�൱��ָ��ڵ㣬��base���У�
    return OK;//����OK
}

Status Stack_Push(LinkStack& s, s_Elemtype e) {//��Ԫ��ѹ��ջ��
    StackNode* newNode = new StackNode;//�����½ڵ�
    if (!newNode) {//�������ʧ����
        exit(ERROR);//ֱ���˳�����
    }
    newNode->data = e;//���н�e��ֵ����data
    newNode->next = s.top;//����ָ��ָ�ؽڵ㣬��Ҳ��Ϊʲô���ʱ�Ƿ���
    //һ���������newNOde -> next = top -> next
    s.top = newNode;//topָ������һ���ڵ���
    return OK;//����OK
}

Status Stack_Pop(LinkStack& s, s_Elemtype& e) {//��ջ��Ԫ�ص���
    if (s.top == NULL) {//���topָ�뻹�ǿյģ���Ϊ��ʱջ��û��Ԫ��
        return ERROR;//���ش���
    };
    e = s.top->data;//ʹ�����ý�ջ��Ԫ�ظ�ֵ��e
    s.top = s.top->next;//topָ��������һλ
    return OK;//������ȷֵ
}

Status Stack_DetTop(LinkStack& s, s_Elemtype& e) {//ɾ��ջ��Ԫ��
    if (s.top != NULL) {//���topָ�벻��NULL����ζ�Ŵ�ʱstack������Ԫ��
        e = s.top->data;//��ô��ջ��Ԫ�ظ�ֵ��e
        return OK;//������ȷ
    }
    return ERROR;//����ջ��û��Ԫ�أ����ش���
}

int main() {
    LinkStack stack1, stack2;//���������µ�ջ��stcak1��stack2
    Init_Stack(stack1);//��ʼ��ջ1
    Init_Stack(stack2);//��ʼ��ջ2��Ŀ�Ļ��Ǳ���ջ1�ڵ�Ԫ�أ������ͷ�ջ1����ʧ
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the stack:" << endl;//����Ҫ����ջԪ�صĸ���
    int num1;cin >> num1;
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the stack:" << endl;//����Ҫ�����Ԫ��
    for (int i = 1; i <= num1; i++) {
        int ele1;cin >> ele1;
        Stack_Push(stack1, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements of the stack are as follows: " << endl;//���stack1�ڵ�Ԫ�أ���ʱջ1��ջ2�໥��
    int cnt = 0;//��¼������������ڵ���
    s_Elemtype topElement;
    while (stack1.top != NULL) {//��stack1��Ԫ�������
        Stack_Pop(stack1, topElement);//��stack1��Ԫ�ص�����ͬʱѹ��stack2
        Stack_Push(stack2, topElement);
        cnt++;
        cout << topElement << " ";//���
    }
    for (int j = 0; j < cnt; j++) {//��stack2��Ԫ���ٵ���stack1
        Stack_Pop(stack2, topElement);
        Stack_Push(stack1, topElement);
    }
    cout << "" << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the stack is:\n ";//���ջ��Ԫ��
    if (Stack_DetTop(stack1, topElement) == OK) cout << topElement << endl;
    else cout << "Stack is empty!" << endl;
    cout << "-------------------------" << endl;
    return 0;
}