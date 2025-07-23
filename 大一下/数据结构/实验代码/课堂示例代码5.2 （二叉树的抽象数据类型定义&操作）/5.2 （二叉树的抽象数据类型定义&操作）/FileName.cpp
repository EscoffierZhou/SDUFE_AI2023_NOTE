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
typedef BiTNode* BiTree;    //��ָ��ṹ���ָ�뵥������

BiTNode* Initialize_Root(TElemtype data) {  //������Ҫ�������ĸ��ڵ㣨���ڽṹ��ĺ�����
    BiTNode* root = new BiTNode;         //�����½ڵ�
    root->data = data;                   //�ڸ��ڵ�Ļ����ϲ�������ݺ�������֧
    root->lchild = nullptr;
    root->rchild = nullptr;
    return root;                         //�������
}

void insertNode(BiTree& root, TElemtype data) { //�������������ʹ��void��
    if (root == nullptr) {              //���û�и��ڵ�ͽ���һ��
        root = Initialize_Root(data);   
    }
    else {                              //����ͻ��ڽڵ��С��������Ҷ��
        if (data < root->data) {          
            insertNode(root->lchild, data);
        }
        else {
            insertNode(root->rchild, data);
        }
    }
}

void In_OrderTraverse(BiTree T) {//����Ҳ�ǲ�����������ָ��ṹ���ָ��T
    if (T) {                    //���ָ��TΪ�ǿգ����������
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
      return max(m, n) + 1;     //��������һ��С���ɱ���дif-else,�Ƚϳ��ϴ�ģ����+1
    }
}

int Nodecount(BiTree T) {
    return (T == nullptr) ? 0 : Nodecount(T->lchild) + Nodecount(T->rchild) + 1;//�ع�һ����Ԫ���ʽ
}

//�����Ǳ���Ҷ�ڵ�Ĵ��룺Ҷ�ڵ���ָû���ӽڵ�Ľڵ�
int leafCount(BiTree T) {
    if (T == nullptr) {
        return 0;
    }
    if (T->lchild == nullptr && T->rchild == nullptr) {
        return 1; // ��ǰ�ڵ�ΪҶ�ڵ㣬����1
    }
    // �ݹ�ͳ������������Ҷ�ڵ����
    return leafCount(T->lchild) + leafCount(T->rchild);
}

int main() {
    BiTree root = nullptr;
    cout << "===========202318140413====����==============" << endl;
    cout << "============================================="<< endl;
    cout << "���������֣�����ĸ��������" << endl;
    TElemtype input;
    while (cin >> input) {
        if (isalpha(input)) // �ж������Ƿ�Ϊ��ĸ
            break;
        insertNode(root, input); // �������ֵ�����
    }
    cout << "������������" << endl;
    In_OrderTraverse(root); // �����������ӡ��
    cout << endl << endl;

    cout << "ǰ����������" << endl;
    Pre_OrderTraverse(root); // ǰ���������ӡ��
    cout << endl << endl;

    cout << "������������" << endl;
    Post_OrderTraverse(root); // �����������ӡ��
    cout << endl << endl;

    cout << "������ȣ�" << depth(root) << endl; // ����������
    cout << "���Ľڵ�����" << Nodecount(root) << endl; // ������Ľڵ���
    cout << "Ҷ�ڵ������" << leafCount(root) << endl; // ���Ҷ�ڵ����
    cout << endl;
    return 0;
}




