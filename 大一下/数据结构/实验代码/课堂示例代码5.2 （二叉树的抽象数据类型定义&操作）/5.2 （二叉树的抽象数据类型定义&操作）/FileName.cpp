#include<iostream>
#include<queue>
#define MAXSIZE 100
typedef int TElemtype;
using namespace std;

struct BiTNode {
    TElemtype data;
    BiTNode* lchild;
    BiTNode* rchild;
};
typedef BiTNode* BiTree;    //将指向结构体的指针单独命名

BiTNode* Initialize_Root(TElemtype data) {  //首先需要创建树的根节点（基于结构体的函数）
    BiTNode* root = new BiTNode;         //建立新节点
    root->data = data;                   //在根节点的基础上插入根数据和两个分支
    root->lchild = nullptr;
    root->rchild = nullptr;
    return root;                         //建立完成
}

void insertNode(BiTree& root, TElemtype data) { //操作函数（因此使用void）
    if (root == nullptr) {              //如果没有根节点就建立一个
        root = Initialize_Root(data);   
    }
    else {                              //否则就基于节点大小分配左右叶子
        if (data < root->data) {          
            insertNode(root->lchild, data);
        }
        else {
            insertNode(root->rchild, data);
        }
    }
}

void In_OrderTraverse(BiTree T) {//这里也是操作，引入了指向结构体的指针T
    if (T) {                    //如果指针T为非空，则中序遍历
        In_OrderTraverse(T->lchild);
        cout << T->data;
        In_OrderTraverse(T->rchild);
    }
}

void Pre_OrderTraverse(BiTree T) {
    if (T) {
        std::cout << T->data;
        Pre_OrderTraverse(T->lchild);
        Pre_OrderTraverse(T->rchild);
    }
}

void Post_OrderTraverse(BiTree T) {
    if (T) {
        Post_OrderTraverse(T->lchild);
        Post_OrderTraverse(T->rchild);
        std::cout << T->data;
    }
}

int depth(BiTree T) {
    if (T == NULL) {
        return 0;
    }else{
      int m = depth(T->lchild);
      int n = depth(T->rchild);
      return max(m, n) + 1;     //这里用了一个小技巧避免写if-else,比较出较大的，结果+1
    }
}

int Nodecount(BiTree T) {
    return (T == nullptr) ? 0 : Nodecount(T->lchild) + Nodecount(T->rchild) + 1;//回顾一下三元表达式
}

//下面是遍历叶节点的代码：叶节点是指没有子节点的节点
int leafCount(BiTree T) {
    if (T == nullptr) {
        return 0;
    }
    if (T->lchild == nullptr && T->rchild == nullptr) {
        return 1; // 当前节点为叶节点，返回1
    }
    // 递归统计左右子树的叶节点个数
    return leafCount(T->lchild) + leafCount(T->rchild);
}

int main() {
    BiTree root = nullptr;
    cout << "===========202318140413====周兴==============" << endl;
    cout << "============================================="<< endl;
    cout << "请输入数字（以字母结束）：" << endl;
    TElemtype input;
    while (cin >> input) {
        if (isalpha(input)) // 判断输入是否为字母
            break;
        insertNode(root, input); // 插入数字到树中
    }
    cout << "中序遍历结果：" << endl;
    In_OrderTraverse(root); // 中序遍历并打印树
    cout << endl << endl;

    cout << "前序遍历结果：" << endl;
    Pre_OrderTraverse(root); // 前序遍历并打印树
    cout << endl << endl;

    cout << "后序遍历结果：" << endl;
    Post_OrderTraverse(root); // 后序遍历并打印树
    cout << endl << endl;

    cout << "树的深度：" << depth(root) << endl; // 输出树的深度
    cout << "树的节点数：" << Nodecount(root) << endl; // 输出树的节点数
    cout << "叶节点个数：" << leafCount(root) << endl; // 输出叶节点个数
    cout << endl;
    return 0;
}




