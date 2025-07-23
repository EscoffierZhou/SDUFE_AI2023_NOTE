#include <stdio.h>
#include <iostream>
using namespace std;
#define Status void
#define OK 1
typedef float Elemtype;
typedef struct Pnode {
    Elemtype coef;
    int exp;
    struct Pnode* next;
} Polynomial;
typedef Polynomial* Polynomia;

//在 CreatPolyn 函数中，我们由于需要修改 P 指针的值，因此将其传递为指向指针的引用 Polynomial*& P。
Status CreatPolyn_Node(Polynomial*& P, int n) {
    P = new Polynomial;
    P->next = NULL;
    Polynomial* pre = P;//使用 pre 指针来跟踪当前节点的前一个节点，以便正确插入新节点。
    Polynomial* q;// 是一个指针，用于遍历多项式链表并找到插入新节点的正确位置。
    for (int i = 1; i <= n; ++i) {//插入n个元素的循环体
        Polynomial* s = new Polynomial;
        cin >> s->coef >> s->exp;
        pre = P;
        q = P->next;
        //真正的循环体
        while (q && q->exp < s->exp) {//条件 q && q->exp < s->exp 确保我们在链表未遍历完（即 q 不为空）且当前节点的指数小于新节点的指数时执行循环体。
            pre = q;//在循环体内，我们将 pre 更新为当前节点 q，然后将 q 更新为下一个节点 q->next，以便继续向后遍历链表。
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

// 在已有函数 Status CreatPolyn(Polynomial& P, int n) 的基础上进行修改
// 将指针的引用改为结构体的引用，以便传递 P 的引用而不是指针的引用
// 注意使用 . 运算符来访问结构体的成员而不是 -> 运算符

Status CreatPolyn_Reference(Polynomial& P, int n) {
    P.next = NULL;
    Polynomial* pre = &P; // 使用 pre 指针来跟踪当前节点的前一个节点，以便正确插入新节点。
    Polynomial* q;
    for (int i = 1; i <= n; ++i) {
        Polynomial* s = new Polynomial;
        cin >> s->coef >> s->exp;
        pre = &P;
        q = P.next;
        while (q && q->exp < s->exp) {
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

Status AddPolyn(Polynomial& Pa, Polynomial& Pb) {
    Polynomial* p1 = Pa.next; // 指向 Pa 多项式链表的第一个节点
    Polynomial* p2 = Pb.next; // 指向 Pb 多项式链表的第一个节点
    Polynomial* p3 = &Pa;     // 指向结果链表的当前节点，初始为 Pa 多项式链表的头节点

    while (p1 && p2) {
        if (p1->exp == p2->exp) { // 当前节点指数相等的情况下
            Elemtype sum = p1->coef + p2->coef; // 计算系数的和
            if (sum != 0) { // 如果和不为0
                p1->coef = sum; // 更新当前节点的系数为和
                p3->next = p1;  // 将当前节点连接到结果链表中
                p3 = p1;        // 更新结果链表的当前节点为当前节点
                p1 = p1->next;  // 移动到 Pa 多项式链表的下一个节点
                Polynomial* r = p2; // 保存 p2 指向的节点
                p2 = p2->next;      // 移动到 Pb 多项式链表的下一个节点
                delete r;           // 删除 p2 指向的节点
            }
            else { // 如果和为0
                Polynomial* r1 = p1; // 保存 p1 指向的节点
                p1 = p1->next;       // 移动到 Pa 多项式链表的下一个节点
                delete r1;           // 删除 p1 指向的节点
                Polynomial* r2 = p2; // 保存 p2 指向的节点
                p2 = p2->next;       // 移动到 Pb 多项式链表的下一个节点
                delete r2;           // 删除 p2 指向的节点
            }
        }
        else {
            if (p1->exp < p2->exp) { // 当前节点指数不相等且 p1 指数小于 p2
                p3->next = p1; // 将当前节点连接到结果链表中
                p3 = p1;       // 更新结果链表的当前节点为当前节点
                p1 = p1->next; // 移动到 Pa 多项式链表的下一个节点
            }
            else { // 当前节点指数不相等且 p1 指数大于 p2
                p3->next = p2; // 将当前节点连接到结果链表中
                p3 = p2;       // 更新结果链表的当前节点为当前节点
                p2 = p2->next; // 移动到 Pb 多项式链表的下一个节点
            }
        }
    }

    p3->next = p1 ? p1 : p2; // 将 Pa 或 Pb 多项式链表中剩余的节点连接到结果链表中
    delete& Pb; // 删除 Pb 多项式链表的头节点
}
