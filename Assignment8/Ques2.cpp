#include <iostream>
using namespace std;
class Tree
{
  public:
  int data;
  Tree* left;
  Tree* right;
  Tree(int x):data(x),left(NULL),right(NULL){}
};
Tree* NRsearch(Tree* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}
Tree* Rsearch(Tree* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return Rsearch(root->left, key);
    return Rsearch(root->right, key);
}
int maxEle(Tree* Root)
{
  if (Root == NULL) return -1;
  if(Root->right==NULL) return Root->data;
  return maxEle(Root->right);
}
int minEle(Tree* Root)
{
  if (Root == NULL) return -1;
  if(Root->left==NULL) return Root->data;
  return maxEle(Root->left);
}
int main()
{
  Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(20);
    root->right->right = new Tree(30);
    int key=20;
    Tree* foundR = Rsearch(root, key);
    cout << "Recursive Search for " << key << ": ";
    if (foundR)
        cout << "Found (" << foundR->data << ")" << endl;
    else
        cout << "Not Found" << endl;
    key=2;
    Tree* foundNR = NRsearch(root, key);
    cout << "Non-Recursive Search for " << key << ": ";
    if (foundNR)
        cout << "Found (" << foundNR->data << ")" << endl;
    else
        cout << "Not Found" << endl;
    cout << "Maximum element: " << maxEle(root) << endl;
    cout << "Minimum element: " << minEle(root) << endl;
    return 0;
}