#include<iostream>
#include<stdlib.h>
#define INIT_SIZE 100
#define OK 1
#define ERROR -1
using namespace std;

/*int fib(int n) {
	if (n == 0)return 1;
	else return n * fib(n - 1);
}

int main() {
	int n; cin >> n;
	cout << fib(n) << endl;
}*/
typedef int Elemtype;
typedef struct Node {   //�����ڽ��ж���
	Elemtype data;      //������
	struct Node* next;  //ָ����(ע������Ӧ����Node�����ָ����)
} Node;

typedef struct Node* Linklist; //Linklist��ָ����Ԫ�ڵ����ָ��

void Travel_list(Linklist p) {
	if (p == NULL)return;
	else cout << p->data << endl; Travel_list(p->next);
}
void Travel_list_Simple(Linklist p) {
	if (p) {
	cout << p->data << endl; 
	Travel_list(p->next);
	}
}
/*ͨ����һ�������������ڼ������һ�������ǣ������б����ú���֮ǰ��ϵͳ��Ҫ��������£�
1. ������ʵ�Σ����ص�ַ�����뱻���ú�������
2. Ϊ�����ú����ľֲ��������䴢����
3. ������ת�Ƶ������ú��������
���ӱ����ú������ص����ú�����Ҳ��������
1. ���汻���ú����ļ�����
2. �ͷű����ú�����������
3. ���ձ����ú�������ķ��ص�ַ������ת�Ƶ����ú���*/

int main() {
	cout << "�ݹ��㷨��Ч�ʷ���" << endl;
		cout << "�ݹ��㷨��ʱ�临�Ӷȷ���" << endl;
			cout << "ֻ������n�ε��ú���������T(n)=O(n)" << endl;
			cout << "���Ǻ�ŵ�����⣬쳲�����������2^n" << endl;
		cout << "�ݹ��㷨�Ŀռ临�Ӷȷ���" << endl;
			cout << "쳲��������У���ŵ�����⣬쳲����������Ƕ���S(n)=O(f(n))" << endl;
}