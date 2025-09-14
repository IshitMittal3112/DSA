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
void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
bool Check_Number(Node* head,int key)
{
  Node* temp=head;
  if(temp->data==key)
  {
    return true;
  }
  else 
  {
    return false;
  }
}
Node* Count_App(Node* head,int key,int &count)
{
  count=0;
  while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
     Node* curr = head;
    while (curr != NULL && curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else {
            curr = curr->next;
        }
    }

    return head;
}
int main() 
{
  int key;
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(1);
  head->next->next->next = new Node(2);
  head->next->next->next->next = new Node(1);
  head->next->next->next->next->next = new Node(3);
  head->next->next->next->next->next->next = new Node(1);
  cout<<"Orignal Linked List:\n";
  print(head);
  cout<<"\nEnter the Number You Want to Check:";
  cin>>key;
  int count = 0;
    head = Count_App(head, key, count);

    cout << "\nCount: " << count << endl;
    cout << "Updated Linked List:\n";
    print(head);

  return 0;
}