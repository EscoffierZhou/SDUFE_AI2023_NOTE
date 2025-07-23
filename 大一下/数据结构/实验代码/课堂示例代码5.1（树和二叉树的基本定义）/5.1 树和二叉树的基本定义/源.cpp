#include<iostream>
#include<cstdio>
*/
#include <iostream>

using namespace std;
//�������Ľṹ��
typedef int DataType;
struct Node
{
    struct Node* firstChild1;
    struct Node* pNextBrother;
    DataType data;
};

// ����������Ľڵ�ṹ
struct TreeNode {
    int data;
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightSibling;

    TreeNode(int val) : data(val), parent(nullptr), leftChild(nullptr), rightSibling(nullptr) {}
};

// �������ṹ
struct Tree {
    TreeNode* root;

    // �������
    Tree() : root(nullptr) {}

    // ������
// ������
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
            // ����parentNodeָ�룬ȷ��ÿ���ڵ�ĸ��ڵ���ȷ
            if (i % 2 == 0)
                parentNode = node;
        }
    }


    // �����Ϊ����
    void clearTree() {
        destroyTree(root);
        root = nullptr;
    }

    // �ж����Ƿ�Ϊ��
    bool isEmpty() {
        return root == nullptr;
    }

    // �����������
    int depth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int leftDepth = depth(node->leftChild);
        int rightDepth = depth(node->rightSibling);
        return max(leftDepth, rightDepth) + 1;
    }

    // �������ĸ��ڵ�
    TreeNode* getRoot() {
        return root;
    }

    // ���ؽڵ��ֵ
    int getNodeValue(TreeNode* node) {
        return node->data;
    }

    // Ϊ�ڵ㸳ֵ
    void setNodeValue(TreeNode* node, int value) {
        node->data = value;
    }

    // ����һ���ڵ��˫��
    TreeNode* getParent(TreeNode* node) {
        return node->parent;
    }

    // ���ؽڵ�����ֵ�
    TreeNode* getLeftSibling(TreeNode* node) {
        if (node->parent == nullptr)
            return nullptr;
        TreeNode* sibling = node->parent->leftChild;
        if (sibling == node)
            return nullptr; // û�����ֵ�
        while (sibling->rightSibling != node)
            sibling = sibling->rightSibling;
        return sibling;
    }

    // ���ؽڵ�����ֵ�
    TreeNode* getRightSibling(TreeNode* node) {
        return node->rightSibling;
    }

    // ��������
    void insertSubTree(TreeNode* node, Tree& subTree) {
        node->leftChild = subTree.root;
    }

    // ɾ������
    void deleteSubTree(TreeNode* node) {
        destroyTree(node->leftChild);
        node->leftChild = nullptr;
    }

    // ������
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
    // ������
    tree.buildTree();

    // �������Ĳ���ʾ��
    if (!tree.isEmpty()) {
        cout << "Tree depth: " << tree.depth(tree.getRoot()) << endl;
        cout << "Root node value: " << tree.getNodeValue(tree.getRoot()) << endl;

        // ������������
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

        // ���Լ���������������
    }

    // �����
    tree.clearTree();

    return 0;
}

