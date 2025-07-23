#include<iostream>
#include<cstdio>
*/
#include <iostream>

using namespace std;
//定义树的结构：
typedef int DataType;
struct Node
{
    struct Node* firstChild1;
    struct Node* pNextBrother;
    DataType data;
};

// 定义二叉树的节点结构
struct TreeNode {
    int data;
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightSibling;

    TreeNode(int val) : data(val), parent(nullptr), leftChild(nullptr), rightSibling(nullptr) {}
};

// 定义树结构
struct Tree {
    TreeNode* root;

    // 构造空树
    Tree() : root(nullptr) {}

    // 构造树
// 构造树
    void buildTree() {
        int numNodes;
        cout << "Enter the number of nodes in the tree: ";
        cin >> numNodes;

        if (numNodes <= 0) {
            cout << "Empty tree created." << endl;
            return;
        }

        cout << "Enter the values of the nodes:" << endl;
        root = nullptr;
        TreeNode* parentNode = nullptr;
        for (int i = 0; i < numNodes; ++i) {
            int value;
            cin >> value;
            TreeNode* node = new TreeNode(value);
            if (root == nullptr) {
                root = node;
                parentNode = node;
            }
            else if (parentNode->leftChild == nullptr) {
                parentNode->leftChild = node;
            }
            else {
                TreeNode* sibling = parentNode->leftChild;
                while (sibling->rightSibling != nullptr)
                    sibling = sibling->rightSibling;
                sibling->rightSibling = node;
            }
            // 更新parentNode指针，确保每个节点的父节点正确
            if (i % 2 == 0)
                parentNode = node;
        }
    }


    // 清空树为空树
    void clearTree() {
        destroyTree(root);
        root = nullptr;
    }

    // 判断树是否为空
    bool isEmpty() {
        return root == nullptr;
    }

    // 返回树的深度
    int depth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int leftDepth = depth(node->leftChild);
        int rightDepth = depth(node->rightSibling);
        return max(leftDepth, rightDepth) + 1;
    }

    // 返回树的根节点
    TreeNode* getRoot() {
        return root;
    }

    // 返回节点的值
    int getNodeValue(TreeNode* node) {
        return node->data;
    }

    // 为节点赋值
    void setNodeValue(TreeNode* node, int value) {
        node->data = value;
    }

    // 返回一个节点的双亲
    TreeNode* getParent(TreeNode* node) {
        return node->parent;
    }

    // 返回节点的左兄弟
    TreeNode* getLeftSibling(TreeNode* node) {
        if (node->parent == nullptr)
            return nullptr;
        TreeNode* sibling = node->parent->leftChild;
        if (sibling == node)
            return nullptr; // 没有左兄弟
        while (sibling->rightSibling != node)
            sibling = sibling->rightSibling;
        return sibling;
    }

    // 返回节点的右兄弟
    TreeNode* getRightSibling(TreeNode* node) {
        return node->rightSibling;
    }

    // 插入子树
    void insertSubTree(TreeNode* node, Tree& subTree) {
        node->leftChild = subTree.root;
    }

    // 删除子树
    void deleteSubTree(TreeNode* node) {
        destroyTree(node->leftChild);
        node->leftChild = nullptr;
    }

    // 销毁树
    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->leftChild);
            destroyTree(node->rightSibling);
            delete node;
        }
    }
};

int main() {
    Tree tree;
    // 构造树
    tree.buildTree();

    // 进行树的操作示例
    if (!tree.isEmpty()) {
        cout << "Tree depth: " << tree.depth(tree.getRoot()) << endl;
        cout << "Root node value: " << tree.getNodeValue(tree.getRoot()) << endl;

        // 调用其他操作
        TreeNode* node = tree.getRoot();
        cout << "Node value: " << tree.getNodeValue(node) << endl;

        tree.setNodeValue(node, 10);
        cout << "New node value: " << tree.getNodeValue(node) << endl;

        TreeNode* parent = tree.getParent(node);
        if (parent != nullptr)
            cout << "Parent node value: " << tree.getNodeValue(parent) << endl;
        else
            cout << "Node has no parent." << endl;

        TreeNode* leftSibling = tree.getLeftSibling(node);
        if (leftSibling != nullptr)
            cout << "Left sibling value: " << tree.getNodeValue(leftSibling) << endl;
        else
            cout << "Node has no left sibling." << endl;

        TreeNode* rightSibling = tree.getRightSibling(node);
        if (rightSibling != nullptr)
            cout << "Right sibling value: " << tree.getNodeValue(rightSibling) << endl;
        else
            cout << "Node has no right sibling." << endl;

        // 可以继续进行其他操作
    }

    // 清空树
    tree.clearTree();

    return 0;
}

