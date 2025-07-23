#include<iostream>  
#include<stdlib.h>
using namespace std;//��׼��ʽ�����
#define MAX_SIZE 100
#define Status int 
#define OVERFLOW -1
#define OK 0
#define ERROR -2
#define EXTENSION_SIZE 10
typedef int s_Elemtype;
typedef struct {    //����ջ�Ľṹ��
    s_Elemtype* base;//�����ָ��
    s_Elemtype* top; //���嶥ָ�루ע�����շ���˳��topָ����baseָ���һλ��

    int stacksize;//����ջ�Ĵ�С
}Sqstack;//������ΪSqstack

Status Init_Stack(Sqstack& s) {//��ʼ��ջ
    s.base = new s_Elemtype[MAX_SIZE];//ʹ��baseָ���new������չһ��MAX_SIZE*sizeof(s_Elemtype)�Ŀռ�
    //s.base = (s_Elemtype*)malloc(MAX_SIZE * sizeof(s_Elemtype));��һ����
    if (!s.base) exit(OVERFLOW);//��ʼ��ʧ�ܣ�����-1
    s.top = s.base;//��baseָ���λ�ø���topָ��
    s.stacksize = MAX_SIZE;//����stacksize��Ŀ�ģ���¼ջ�Ĵ�С
    return OK;//����0
}

Status Stack_Push(Sqstack& s, s_Elemtype e) {//ջԪ�صĲ���
    if (s.top - s.base == s.stacksize) { // ջ����������ջ����չ
        s_Elemtype* newBase = (s_Elemtype*)realloc(s.base, (s.stacksize + EXTENSION_SIZE) * sizeof(s_Elemtype));//ʹ��realloc�������·���һ��size+1��λ��
        if (!newBase) {//���realloc��������ʧ�ܣ��ڴ�̫С����������ʲô������
            return ERROR;
        }
        s.base = newBase;//baseָ�뵽�µ�base��
        s.top = s.base + s.stacksize;//topҪ��base�Ļ����ϼ���Ŀǰջ�Ĵ�С
        s.stacksize += 1;//��ʱջ�Ĵ�С��1��Ŀ���Ǹ���Ԫ���ڵط���
    }
    *s.top++ = e;//��eԪ�ص�ֵ��ֵ���ոտ��ٵĿռ���
    return OK;//������ȷ
}

Status Stack_Pop(Sqstack& s, s_Elemtype& e) {//ջԪ�صĵ���
    if (s.top == s.base) return ERROR;//���û��Ԫ�أ����ش���
    e = *--s.top;//��ɾ����Ԫ�ظ�ֵ��e����Ϊ�����ã�ԭeֱ�Ӷ�Ӧ��ֵ
    return OK;//���سɹ�
}

Status Stack_DetTop(Sqstack& s, s_Elemtype& e) {//ջ��Ԫ�صĵ���
    if (s.top != s.base) {//���ջ�ڴ���Ԫ�ز�ִ�д˲���
        e = *(s.top - 1);//��ջ��Ԫ�ص�ֵ����e
        return OK;//�������
    }
    return ERROR;//����δ��ɲ���
}

int main() {
    Sqstack stack1, stack2;//�½�����ջ��Ŀ���Ǻ��������ʱ���ã�����ջ1Ԫ�صĶ�ʧ
    Init_Stack(stack1);//��ʼ��ջ1
    Init_Stack(stack2);//��ʼ��ջ2
    cout << "-------------------------" << endl;
    cout << "Insert the number of elements you want to push into the stack:" << endl;
    int num1; cin >> num1;//����num1��Ȼ�����num1
    cout << "-------------------------" << endl;
    cout << "Insert the elements you want to push into the stack:" << endl;
    for (int i = 1; i <= num1; i++) {//����num1��Ԫ��
        int ele1; cin >> ele1;
        Stack_Push(stack1, ele1);
    }
    cout << "-------------------------" << endl;
    cout << "The elements of the stack are as follows: " << endl;//���ջ1������Ԫ�أ���ʱ�ᷢ�ֶ��ǵ�������ģ�
    int cnt = 0;
    s_Elemtype topElement;//ɾ��ջ��Ԫ��
    while (stack1.top != stack1.base) {//��ջ1������Ԫ�������ͬʱѹ��ջ2
        Stack_Pop(stack1, topElement);
        Stack_Push(stack2, topElement);
        cnt++;
        cout << topElement << " ";//���ջ1��Ԫ��
    }
    for (int j = 0; j < cnt; j++) {//�ٽ��ո�ջ2ѹ���Ԫ�ص����ջ1����ʱջ1�൱��û�б仯
        Stack_Pop(stack2, topElement);
        Stack_Push(stack1, topElement);
    }
    cout << "" << endl;
    cout << "-------------------------" << endl;
    cout << "The top element of the stack is: "<<endl;//���ջ��Ԫ��
    if (Stack_DetTop(stack1, topElement) == OK) {//������ֵ�����OK��Ӧ��ֵ�����ջ��Ԫ��
        cout << topElement << endl;
    }
    else {//����ջ���ǿյ�
        cout << "Stack is empty!" << endl;
    }
    cout << "-------------------------" << endl;

    return 0;//��������
}