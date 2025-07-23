#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
typedef int Elemtype;
typedef int complex;
using namespace std;
#define Day1 void
//数值交换代码(引用)
Day1 swap(Elemtype &a, Elemtype &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//数值交换代码（指针）
Day1 swap2(Elemtype* p1, Elemtype* p2) {
    Elemtype temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// 复数求和代码(重点复习)
typedef struct Complex {
    Elemtype realpart;
    Elemtype imagpart;
} Complex;

Day1 add(Complex z1, Complex z2, Complex& result) {
    result.realpart = z1.realpart + z2.realpart;
    result.imagpart = z1.imagpart + z2.imagpart;
}



int main() {
  //1.数值交换部分
    int x, y;
    std::cin >> x >> y;
    swap2(&x, &y);
    std::cout << x << " " << y << std::endl;
    return 0;
  //2.复数求和部分
    Complex z1, z2, sum;
    // 输入复数 z1 的实部和虚部
    std::cout << "Enter real part of z1: ";
    std::cin >> z1.realpart;
    std::cout << "Enter imaginary part of z1: ";
    std::cin >> z1.imagpart;
    // 输入复数 z2 的实部和虚部
    std::cout << "Enter real part of z2: ";
    std::cin >> z2.realpart;
    std::cout << "Enter imaginary part of z2: ";
    std::cin >> z2.imagpart;
    // 调用复数求和函数
    add(z1, z2, sum);
    // 输出结果
    std::cout << "Sum of the complex numbers: " << sum.realpart << " + " << sum.imagpart << "i\n";


    return 0;
}