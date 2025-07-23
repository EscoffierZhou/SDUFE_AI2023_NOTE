#include<iostream>
#include<string>
#include<cstdlib> // For malloc and realloc
#include<cstdio>
using namespace std;

#define OK 1
#define ERROR -1
#define INIT_SIZE 100
#define EXTENSION_SIZE 10
typedef int Status;
typedef int s_Elemtype;
typedef struct {
    s_Elemtype* base; // ջ�Ļ�ַ
    s_Elemtype* top;  // ջ��ָ��
    int stacksize;    // ��ǰջ�Ĵ�С
} Sqstack;

// ��ʼ��ջ
Status STACK_INIT(Sqstack& s) {
    s.base = (s_Elemtype*)malloc(sizeof(s_Elemtype) * INIT_SIZE); // Ϊջ�����ʼ�ڴ�
    if (!s.base) return ERROR; // �ڴ����ʧ��
    s.top = s.base; // ջ��ָ��ָ��ջ��
    s.stacksize = INIT_SIZE; // ���ó�ʼջ��С
    return OK;
}

// ��ջ����
Status STACK_PUSH(Sqstack& s, s_Elemtype e) {
    if (s.top - s.base == s.stacksize) { // ջ��ʱ��Ҫ��չ�ڴ�
        s_Elemtype* newbase = (s_Elemtype*)realloc(s.base, (s.stacksize + EXTENSION_SIZE) * sizeof(s_Elemtype)); // ��չ�ڴ�
        if (!newbase) return ERROR; // ��չʧ��
        s.base = newbase; // ����ջ��ַ
        s.top = s.base + s.stacksize; // ����ջ��ָ��
        s.stacksize += EXTENSION_SIZE; // ����ջ��С
    }
    *s.top++ = e; // ��Ԫ����ջ
    return OK;
}

// ��ջ����
Status STACK_POP(Sqstack& s, s_Elemtype& e) {
    if (s.top == s.base) return ERROR; // ջ��ʱ�޷���ջ
    e = *--s.top; // ��ջ��Ԫ�س�ջ
    return OK;
}

int main() {
    cout << "--------------------------------------" << endl;
    cout << "This is the homework from Zhouxing in AI2302" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Ok, now you can insert the numbers you want to trans" << endl;
    Sqstack stack1;
    STACK_INIT(stack1); // ��ʼ��ջ
    int x, y;
    cin >> x;
    cout << "The number required is " << x << endl;

    // ��ʮ������ת��Ϊ�˽���������ջ
    while (x != 0) {
        y = x % 8;
        STACK_PUSH(stack1, y); // ��������ջ
        x /= 8; // ��������Ϊ��һ�ּ���ı�����
    }

    int e, a[100], cnt = 0;
    cout << "--------------------------------------" << endl;
    cout << "Well, the % process is as follows" << endl;
    // ���γ�ջ�������λ�˽�������
    while (STACK_POP(stack1, e) != ERROR) {
        cout << e << endl;
        a[cnt] = e; // ����ջ��Ԫ�ر��浽������
        cnt++; // ͳ�Ƴ�ջԪ�ظ���
    }

    cout << "--------------------------------------" << endl;
    cout << "The final answer is " << endl;
    // ������������еİ˽������֣��õ����ս��
    for (int j =0; j < cnt ; j++) {
        cout << a[j];
    }

    return 0;
}