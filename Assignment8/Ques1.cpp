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
void inorder(Tree* root)
{
  if(root==NULL)
  return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void preorder(Tree* root)
{
  if(root==NULL)
  return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
void postorder(Tree* root)
{
  if(root==NULL)
  return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}
int main()
{
  Tree* root=new Tree(1);
  root->left=new Tree(2);
  root->right=new Tree(3);
  root->right->left=new Tree(7);
  root->right->right=new Tree(8);
  root->right->right->left=new Tree(9);
  root->right->right->right=new Tree(10);
  root->left->left=new Tree(4);
  root->left->right=new Tree(5);
  root->left->right->left=new Tree(6);
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  return 0;
}