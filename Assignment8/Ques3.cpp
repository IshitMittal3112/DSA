#include <iostream>
#include <algorithm>
using namespace std;

class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) : data(val), left(nullptr), right(nullptr) {}
};

Tree* insert(Tree* root, int key) {
    if (!root) return new Tree(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

Tree* findMin(Tree* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Tree* deleteNode(Tree* root, int key) {
    if (!root) return nullptr;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Tree* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Tree* temp = root->left;
            delete root;
            return temp;
        } else {
            Tree* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int maxDepth(Tree* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Tree* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Tree* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Tree* root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int val : values)
        root = insert(root, val);

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    root = deleteNode(root, 10);
    cout << "After deleting 10, In-order: ";
    inorder(root);
    cout << endl;

    return 0;
}