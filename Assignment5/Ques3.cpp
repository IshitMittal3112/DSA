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
int count_dig(Node* head,int &count)
{
  Node* temp=head;
  count=0;
  while (temp!=NULL)
  {
    temp=temp->next;
    count++;
  }
  return count;
}
int Mid_Element(Node* head,int n)
{
  int i;
  Node* temp= head;
  for (i=0;i<n/2;i++)
  {
    temp=temp->next;
  }
  return temp->data;
}
int main() 
{
  int count=0;
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  cout<<"Orignal Linked List:\n";
  print(head);
  count=count_dig(head,count);
  int val=Mid_Element(head,count);
  cout<<"\nValue at mid is:"<<val;
  return 0;
}