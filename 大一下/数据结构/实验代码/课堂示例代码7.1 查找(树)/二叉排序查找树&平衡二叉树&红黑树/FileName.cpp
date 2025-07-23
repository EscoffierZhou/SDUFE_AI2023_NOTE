#include <iostream>
#include <algorithm>

using namespace std;

// ���ֲ�������BST���ڵ�ṹ
struct BSTNode {
    int data;               // �ڵ�洢������
    BSTNode* left;          // ���ӽڵ�ָ��
    BSTNode* right;         // ���ӽڵ�ָ��

    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// ���ֲ�������BST����
class BST {
public:
    BST() : root(nullptr) {}

    // ��������
    void insert(int data) {
        root = insert(root, data);
    }

    // ɾ������
    void remove(int data) {
        root = remove(root, data);
    }

    // �������
    void inorder() {
        inorder(root);
        cout << endl;
    }

protected:
    BSTNode* root;  // ���ڵ�ָ��

    // �ݹ��������
    BSTNode* insert(BSTNode* node, int data) {
        if (!node) return new BSTNode(data);  // �����ǰ�ڵ�Ϊ�գ������½ڵ�
        if (data < node->data) node->left = insert(node->left, data);  // ����С�ڵ�ǰ�ڵ㣬����������
        else if (data > node->data) node->right = insert(node->right, data);  // ���ݴ��ڵ�ǰ�ڵ㣬����������
        return node;
    }

    // �ݹ�ɾ������
    BSTNode* remove(BSTNode* node, int data) {
        if (!node) return node;  // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
        if (data < node->data) node->left = remove(node->left, data);  // ����С�ڵ�ǰ�ڵ㣬��������ɾ��
        else if (data > node->data) node->right = remove(node->right, data);  // ���ݴ��ڵ�ǰ�ڵ㣬��������ɾ��
        else {
            // ��ǰ�ڵ㼴Ϊ��Ҫɾ���Ľڵ�
            if (!node->left) {  // �ڵ�û��������
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {  // �ڵ�û��������
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            // �ڵ��������������ҵ��������е���Сֵ�滻��ǰ�ڵ�
            BSTNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // ������Сֵ�ڵ�
    BSTNode* minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // ���������������
    void inorder(BSTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

// AVL���ڵ�ṹ���̳���BSTNode
struct AVLNode : public BSTNode {
    int height;  // �ڵ�߶�

    AVLNode(int val) : BSTNode(val), height(1) {}
};

// AVL���࣬�̳���BST
class AVLTree : public BST {
public:
    AVLTree() : BST() {}

    void insert(int data) {
        root = insert(static_cast<AVLNode*>(root), data);
    }

    void remove(int data) {
        root = remove(static_cast<AVLNode*>(root), data);
    }

    // �������
    void inorder() {
        BST::inorder(root);
    }

private:
    // ��ȡ�ڵ�߶�
    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    // ��ȡ�ڵ�ƽ������
    int getBalance(AVLNode* node) {
        return node ? height(static_cast<AVLNode*>(node->left)) - height(static_cast<AVLNode*>(node->right)) : 0;
    }

    // ����ת
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = static_cast<AVLNode*>(y->left);
        AVLNode* T2 = static_cast<AVLNode*>(x->right);

        x->right = y;
        y->left = T2;

        y->height = max(height(static_cast<AVLNode*>(y->left)), height(static_cast<AVLNode*>(y->right))) + 1;
        x->height = max(height(static_cast<AVLNode*>(x->left)), height(static_cast<AVLNode*>(x->right))) + 1;

        return x;
    }

    // ����ת
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = static_cast<AVLNode*>(x->right);
        AVLNode* T2 = static_cast<AVLNode*>(y->left);

        y->left = x;
        x->right = T2;

        x->height = max(height(static_cast<AVLNode*>(x->left)), height(static_cast<AVLNode*>(x->right))) + 1;
        y->height = max(height(static_cast<AVLNode*>(y->left)), height(static_cast<AVLNode*>(y->right))) + 1;

        return y;
    }

    // �������ݲ�ƽ����
    AVLNode* insert(AVLNode* node, int data) {
        if (!node) return new AVLNode(data);
        if (data < node->data) node->left = insert(static_cast<AVLNode*>(node->left), data);
        else if (data > node->data) node->right = insert(static_cast<AVLNode*>(node->right), data);
        else return node;

        node->height = 1 + max(height(static_cast<AVLNode*>(node->left)), height(static_cast<AVLNode*>(node->right)));
        int balance = getBalance(node);

        if (balance > 1 && data < node->left->data) return rightRotate(node);
        if (balance < -1 && data > node->right->data) return leftRotate(node);
        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(static_cast<AVLNode*>(node->left));
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(static_cast<AVLNode*>(node->right));
            return leftRotate(node);
        }

        return node;
    }

    // ɾ�����ݲ�ƽ����
    AVLNode* remove(AVLNode* root, int data) {
        if (!root) return root;

        if (data < root->data) root->left = remove(static_cast<AVLNode*>(root->left), data);
        else if (data > root->data) root->right = remove(static_cast<AVLNode*>(root->right), data);
        else {
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? static_cast<AVLNode*>(root->left) : static_cast<AVLNode*>(root->right);
                if (!temp) {
                    temp = root;
                    root = nullptr;
                }
                else *root = *temp;
                delete temp;
            }
            else {
                AVLNode* temp = minValueNode(static_cast<AVLNode*>(root->right));
                root->data = temp->data;
                root->right = remove(static_cast<AVLNode*>(root->right), temp->data);
            }
        }

        if (!root) return root;

        root->height = 1 + max(height(static_cast<AVLNode*>(root->left)), height(static_cast<AVLNode*>(root->right)));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(static_cast<AVLNode*>(root->left)) >= 0) return rightRotate(root);
        if (balance > 1 && getBalance(static_cast<AVLNode*>(root->left)) < 0) {
            root->left = leftRotate(static_cast<AVLNode*>(root->left));
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(static_cast<AVLNode*>(root->right)) <= 0) return leftRotate(root);
        if (balance < -1 && getBalance(static_cast<AVLNode*>(root->right)) > 0) {
            root->right = rightRotate(static_cast<AVLNode*>(root->right));
            return leftRotate(root);
        }

        return root;
    }

    // ������Сֵ�ڵ�
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left) current = static_cast<AVLNode*>(current->left);
        return current;
    }
};

// ������ڵ���ɫö��
enum Color { RED, BLACK };

// ������ڵ�ṹ���̳���BSTNode
struct RBNode : public BSTNode {
    Color color;  // �ڵ���ɫ

    RBNode(int val) : BSTNode(val), color(RED) {}
};

// �������
class RBTree {
public:
    RBTree() : root(nullptr) {}

    // ��������
    void insert(int data) {
        root = insert(root, data);
        root->color = BLACK;  // ���ڵ����Ϊ��ɫ
    }

    // �������
    void inorder() {
        inorder(root);
        cout << endl;
    }

private:
    RBNode* root;  // ���ڵ�ָ��

    // �������ݲ����������
    RBNode* insert(RBNode* node, int data) {
        if (!node) return new RBNode(data);
        if (data < node->data) node->left = insert(static_cast<RBNode*>(node->left), data);
        else if (data > node->data) node->right = insert(static_cast<RBNode*>(node->right), data);
        else return node;

        if (isRed(static_cast<RBNode*>(node->right)) && !isRed(static_cast<RBNode*>(node->left))) node = leftRotate(node);
        if (isRed(static_cast<RBNode*>(node->left)) && isRed(static_cast<RBNode*>(node->left->left))) node = rightRotate(node);
        if (isRed(static_cast<RBNode*>(node->left)) && isRed(static_cast<RBNode*>(node->right))) flipColors(node);

        return node;
    }

    // �жϽڵ��Ƿ�Ϊ��ɫ
    bool isRed(RBNode* node) {
        return node != nullptr && node->color == RED;
    }

    // ����ת
    RBNode* leftRotate(RBNode* h) {
        RBNode* x = static_cast<RBNode*>(h->right);
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    // ����ת
    RBNode* rightRotate(RBNode* h) {
        RBNode* x = static_cast<RBNode*>(h->left);
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    // ��ɫ��ת
    void flipColors(RBNode* h) {
        h->color = RED;
        static_cast<RBNode*>(h->left)->color = BLACK;
        static_cast<RBNode*>(h->right)->color = BLACK;
    }

    // ���������������
    void inorder(BSTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    cout << "Binary Search Tree (BST) operations:" << endl;
    BST bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(15);
    bst.inorder();  // �������������
    bst.remove(10);
    bst.inorder();  // �������������

    cout << "\nAVL Tree operations:" << endl;
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(15);
    avl.inorder();  // �������������
    avl.remove(10);
    avl.inorder();  // �������������

    cout << "\nRed-Black Tree operations:" << endl;
    RBTree rb;
    rb.insert(10);
    rb.insert(20);
    rb.insert(5);
    rb.insert(15);
    rb.inorder();  // �������������

    return 0;
}
