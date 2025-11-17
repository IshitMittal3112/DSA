#include <iostream>
using namespace std;
class Tree
{
public:
  int data;
  Tree *left;
  Tree *right;
  Tree(int x) : data(x), left(NULL), right(NULL) {}
};
Tree *NRsearch(Tree *root, int key)
{
  while (root != nullptr)
  {
    if (root->data == key)
      return root;
    else if (key < root->data)
      root = root->left;
    else
      root = root->right;
  }
  return nullptr;
}
Tree *Rsearch(Tree *root, int key)
{
  if (root == nullptr || root->data == key)
    return root;
  if (key < root->data)
    return Rsearch(root->left, key);
  return Rsearch(root->right, key);
}
int maxEle(Tree *Root)
{
  if (Root == NULL)
    return -1;
  if (Root->right == NULL)
    return Root->data;
  return maxEle(Root->right);
}
int minEle(Tree *Root)
{
  if (Root == NULL)
    return -1;
  if (Root->left == NULL)
    return Root->data;
  return maxEle(Root->left);
}
int inordersuccesor(Tree *root, int key)
{
  Tree *successor = nullptr;
  Tree *current = root;

  while (current != nullptr)
  {
    if (key < current->data)
    {
      successor = current;
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return successor ? successor->data : -1;
}
int inorderpredecessor(Tree *root, int key)
{
  Tree *current = root;
  Tree *predecessor = nullptr;

  while (current != nullptr)
  {
    if (key > current->data)
    {
      predecessor = current;
      current = current->right;
    }
    else
    {
      current = current->left;
    }
  }

  return predecessor ? predecessor->data : -1;
}

int main()
{
  Tree *root = new Tree(10);
  root->left = new Tree(5);
  root->right = new Tree(20);
  root->right->right = new Tree(30);
  int key = 20;
  Tree *foundR = Rsearch(root, key);
  cout << "Recursive Search for " << key << ": ";
  if (foundR)
    cout << "Found (" << foundR->data << ")" << endl;
  else
    cout << "Not Found" << endl;
  key = 2;
  Tree *foundNR = NRsearch(root, key);
  cout << "Non-Recursive Search for " << key << ": ";
  if (foundNR)
    cout << "Found (" << foundNR->data << ")" << endl;
  else
    cout << "Not Found" << endl;
  cout << "Maximum element: " << maxEle(root) << endl;
  cout << "Minimum element: " << minEle(root) << endl;
  int succ = inordersuccesor(root, 10);
  if (succ != -1)
    cout << "Inorder Successor of 10: " << succ << endl;
  else
    cout << "Inorder Successor not found" << endl;
  int pred = inorderpredecessor(root, 20);
  if (pred != -1)
    cout << "Inorder Predecessor of 20: " << pred << endl;
  else
    cout << "Inorder Predecessor not found" << endl;
  return 0;
}