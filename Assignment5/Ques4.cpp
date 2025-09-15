#include <iostream>
using namespace std;
class Node
{
  public:
  int data;
  Node* next;
  Node(int data)
  {
    this->data=data;
    this->next=NULL;
  }
};
void print(Node *head)
{
  while (head != NULL) 
  {
      cout << head->data << " ";
      head = head->next;
  }
    cout << endl;
}
Node* Reverse_List(Node* head)
{
  Node* prev=NULL;
  Node* temp=head;
  Node* next=NULL;
  while(temp!=NULL)
  {
    next=temp->next;
    temp->next=prev;
    prev=temp;
    temp=next;
  }
  return prev;
}
int main() 
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  cout<<"Orignal Linked List:\n";
  print(head);
  cout<<"\nList After Revesing:\n";
  head=Reverse_List(head);
  print(head);
  return 0;
}