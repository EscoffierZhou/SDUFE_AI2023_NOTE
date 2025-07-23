#define  _CRT_SECURE_NO_WARNINGS//Vscode的scanf报错
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <stdio.h>

#define OK 1
#define ERROR 0
#define overflow -2

typedef int Elemtype;
typedef int Status;

typedef struct Node {   //对链节进行定义
    Elemtype data;      //数据域
    struct Node* next;  //指针域(注意这里应该是Node本身的指针域)
} Node;

typedef struct Node* Linklist; //Linklist是指向首元节点的首指针

typedef struct DuNode { //对双向链表进行定义
    Elemtype data;          //数据域
    struct DuNode* prior;   //前向指针
    struct DuNode* next;    //后向指针
} DuNode;

typedef DuNode* DuLinklist;

Status InitList(Linklist& L) {  //构造一个空的单链表L（初始化首元节点）
    L = new Node;       //头指针指向新生成的Node
    L->next = NULL;     //我们这时让在Node指针域的指针指向NULL避免野指针
    return OK;
}

Status GetElem(Linklist L, int i, Elemtype& e) {//在带头节点的单链表L中根据i获取元素的值，用e返回第i个元素的值
    Node* p = L->next;        //因为是中间节点所以指向next而不是NULL
    Elemtype j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

Node* locateElem(Linklist L, Elemtype e) { //返回的是节点的地址所以这里使用Node起手
    Node* p = L->next;                    //都需要创造首元节点
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}

Status ListInsert(Linklist& L, int i, Elemtype e) {//指定位置插入
    Node* p = L;
    Elemtype j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    Node* s = new Node;
    s->data = e;
    s->next = p->next;     //隔空链接
    p->next = s;
    return OK;
}

Status ListDelete(Linklist& L, int i) {//删除指定位置节点
    Node* p = L;
    Elemtype j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1)) return ERROR;
    Node* q = p->next;
    p->next = q->next;
    delete q;
    return OK;
}

void CreateList_Q(Linklist& L, int n) {//插入元素：
    L = new Node;
    L->next = NULL;
    for (int i = 0; i < n; ++i) {
        Node* p = new Node;
        std::cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

void CreatList_R(Linklist& L, int n) {//后插法插入
    L = new Node;
    L->next = NULL;
    Node* r = L;
    for (int i = 0; i < n; ++i) {
        Node* p = new Node;
        std::cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void MergeList_L(Linklist& LA, Linklist& LB, Linklist& LC) {
    Node* pa = LA->next;
    Node* pb = LB->next;
    Node* pc = LC;

    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa ? pa : pb;
}

int main() {
    Linklist L1,L2;
    InitList(L1);
    InitList(L2);
    printf("-------------------------\n");
    printf("Inserting elements at specific positions:Insert the quantity of the inserted number\n");
    int n;
    scanf("%d", &n);
    printf("-------------------------\n");
    printf("Insert the elements of the inserted number\n");
    for (int i = 1; i <= n; i++) {
        int ele1;
        scanf("%d", &ele1);
        ListInsert(L1, i, ele1);
    }

    printf("-------------------------\n");
    printf("The elements of the l1 is: \n ");
    Node* p = L1->next;
    while (p != NULL) {
        printf("%d\n ", p->data);
        p = p->next;
    }
    printf("------------------------\n");

 
    printf("Getting an element at a specific position:Insert the position of the inserted number\n");
    printf("------------------------\n");
    int pos; scanf("%d",&pos);
    Elemtype e;
    if (GetElem(L1, pos, e) == OK) {
        printf("Element at the fixed position : %d\n", e);
        printf("------------------------\n");
    }
    else {
        printf("Failed to get element at position .\n");
        printf("------------------------\n");
    }


    printf("Finding the location of an element,Insert the position of the located number\n");
    printf("------------------------\n");
    int pos2; scanf("%d", &pos2);
    Node* location = locateElem(L1, pos2);
    if (location != NULL) {
        printf("Location of element : %p\n", location);
        printf("------------------------\n");
    }
    else {
        printf("Element 20 not found.\n");
        printf("------------------------\n");
    }

    printf("Deleting an element at a specific position,Insert the position of the specific deleting number\n");
    printf("------------------------\n");
    int pos3; scanf("%d", &pos3);
    if (ListDelete(L1, pos3) == OK) {
        printf("Element at noticedposition deleted successfully.\n");
        printf("------------------------\n");
    }
    else {
        printf("Failed to delete element at position 3.\n");
        printf("------------------------\n");
    }


    printf("Displaying the updated list,The list which edited before: \n");
    p = L1->next;
    while (p != NULL) {
        printf("%d \n", p->data);
        p = p->next;
    }
    printf("------------------------\n");

 
    return 0;
}













































/*typedef struct Node {
    Elemtype data;
    struct LNode *next;
} LNode;
typedef LNode* Linklist;
//这两句话等于}Lnode,*Linklist;

Status InitList(Linklist& L) {
    L = new Node;
    L->next = NULL;
    return OK;
}//初始化链表
//流程：形成头节点，用指针L指向头节点->头节点指针域留空

Status Getelem(Linklist& L, int i, Elemtype& e) {
    int j = 1;
    Lnode* p = L->next; // 定义并初始化指针变量 p
    while (p != nullptr && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}
int main() {

}
*/