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
typedef struct Node {   //对链节进行定义
	Elemtype data;      //数据域
	struct Node* next;  //指针域(注意这里应该是Node本身的指针域)
} Node;

typedef struct Node* Linklist; //Linklist是指向首元节点的首指针

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
/*通常，一个函数再运行期间调用另一个函数是，在运行被调用函数之前，系统需要完成三件事：
1. 将所有实参，返回地址，传入被调用函数保存
2. 为被调用函数的局部变量分配储存区
3. 将控制转移到被调用函数的入口
而从被调用函数返回到调用函数，也有三件事
1. 保存被调用函数的计算结果
2. 释放被调用函数的数据区
3. 依照被调用函数保存的返回地址将控制转移到调用函数*/

int main() {
	cout << "递归算法的效率分析" << endl;
		cout << "递归算法的时间复杂度分析" << endl;
			cout << "只不过是n次倒用函数，所以T(n)=O(n)" << endl;
			cout << "但是汉诺塔问题，斐波那契数列是2^n" << endl;
		cout << "递归算法的空间复杂度分析" << endl;
			cout << "斐波那契数列，汉诺塔问题，斐波那契数列是都是S(n)=O(f(n))" << endl;
}