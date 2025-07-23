#include <iostream>
#include <algorithm>

using namespace std;

// 二分查找树（BST）节点结构
struct BSTNode {
    int data;               // 节点存储的数据
    BSTNode* left;          // 左子节点指针
    BSTNode* right;         // 右子节点指针

    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 二分查找树（BST）类
class BST {
public:
    BST() : root(nullptr) {}

    // 插入数据
    void insert(int data) {
        root = insert(root, data);
    }

    // 删除数据
    void remove(int data) {
        root = remove(root, data);
    }

    // 中序遍历
    void inorder() {
        inorder(root);
        cout << endl;
    }

protected:
    BSTNode* root;  // 根节点指针

    // 递归插入数据
    BSTNode* insert(BSTNode* node, int data) {
        if (!node) return new BSTNode(data);  // 如果当前节点为空，创建新节点
        if (data < node->data) node->left = insert(node->left, data);  // 数据小于当前节点，插入左子树
        else if (data > node->data) node->right = insert(node->right, data);  // 数据大于当前节点，插入右子树
        return node;
    }

    // 递归删除数据
    BSTNode* remove(BSTNode* node, int data) {
        if (!node) return node;  // 如果当前节点为空，直接返回
        if (data < node->data) node->left = remove(node->left, data);  // 数据小于当前节点，从左子树删除
        else if (data > node->data) node->right = remove(node->right, data);  // 数据大于当前节点，从右子树删除
        else {
            // 当前节点即为需要删除的节点
            if (!node->left) {  // 节点没有左子树
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {  // 节点没有右子树
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            // 节点有两个子树，找到右子树中的最小值替换当前节点
            BSTNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // 查找最小值节点
    BSTNode* minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    // 中序遍历辅助函数
    void inorder(BSTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

// AVL树节点结构，继承自BSTNode
struct AVLNode : public BSTNode {
    int height;  // 节点高度

    AVLNode(int val) : BSTNode(val), height(1) {}
};

// AVL树类，继承自BST
class AVLTree : public BST {
public:
    AVLTree() : BST() {}

    void insert(int data) {
        root = insert(static_cast<AVLNode*>(root), data);
    }

    void remove(int data) {
        root = remove(static_cast<AVLNode*>(root), data);
    }

    // 中序遍历
    void inorder() {
        BST::inorder(root);
    }

private:
    // 获取节点高度
    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    // 获取节点平衡因子
    int getBalance(AVLNode* node) {
        return node ? height(static_cast<AVLNode*>(node->left)) - height(static_cast<AVLNode*>(node->right)) : 0;
    }

    // 右旋转
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = static_cast<AVLNode*>(y->left);
        AVLNode* T2 = static_cast<AVLNode*>(x->right);

        x->right = y;
        y->left = T2;

        y->height = max(height(static_cast<AVLNode*>(y->left)), height(static_cast<AVLNode*>(y->right))) + 1;
        x->height = max(height(static_cast<AVLNode*>(x->left)), height(static_cast<AVLNode*>(x->right))) + 1;

        return x;
    }

    // 左旋转
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = static_cast<AVLNode*>(x->right);
        AVLNode* T2 = static_cast<AVLNode*>(y->left);

        y->left = x;
        x->right = T2;

        x->height = max(height(static_cast<AVLNode*>(x->left)), height(static_cast<AVLNode*>(x->right))) + 1;
        y->height = max(height(static_cast<AVLNode*>(y->left)), height(static_cast<AVLNode*>(y->right))) + 1;

        return y;
    }

    // 插入数据并平衡树
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

    // 删除数据并平衡树
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

    // 查找最小值节点
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left) current = static_cast<AVLNode*>(current->left);
        return current;
    }
};

// 红黑树节点颜色枚举
enum Color { RED, BLACK };

// 红黑树节点结构，继承自BSTNode
struct RBNode : public BSTNode {
    Color color;  // 节点颜色

    RBNode(int val) : BSTNode(val), color(RED) {}
};

// 红黑树类
class RBTree {
public:
    RBTree() : root(nullptr) {}

    // 插入数据
    void insert(int data) {
        root = insert(root, data);
        root->color = BLACK;  // 根节点必须为黑色
    }

    // 中序遍历
    void inorder() {
        inorder(root);
        cout << endl;
    }

private:
    RBNode* root;  // 根节点指针

    // 插入数据并调整红黑树
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

    // 判断节点是否为红色
    bool isRed(RBNode* node) {
        return node != nullptr && node->color == RED;
    }

    // 左旋转
    RBNode* leftRotate(RBNode* h) {
        RBNode* x = static_cast<RBNode*>(h->right);
        h->right = x->left;
        x->left = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    // 右旋转
    RBNode* rightRotate(RBNode* h) {
        RBNode* x = static_cast<RBNode*>(h->left);
        h->left = x->right;
        x->right = h;
        x->color = h->color;
        h->color = RED;
        return x;
    }

    // 颜色翻转
    void flipColors(RBNode* h) {
        h->color = RED;
        static_cast<RBNode*>(h->left)->color = BLACK;
        static_cast<RBNode*>(h->right)->color = BLACK;
    }

    // 中序遍历辅助函数
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
    bst.inorder();  // 输出中序遍历结果
    bst.remove(10);
    bst.inorder();  // 输出中序遍历结果

    cout << "\nAVL Tree operations:" << endl;
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(5);
    avl.insert(15);
    avl.inorder();  // 输出中序遍历结果
    avl.remove(10);
    avl.inorder();  // 输出中序遍历结果

    cout << "\nRed-Black Tree operations:" << endl;
    RBTree rb;
    rb.insert(10);
    rb.insert(20);
    rb.insert(5);
    rb.insert(15);
    rb.inorder();  // 输出中序遍历结果

    return 0;
}
