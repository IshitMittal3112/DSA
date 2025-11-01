#include <iostream>
#include <vector>
using namespace std;
class Node
{
  public:
  int data;
  Node* next;
  Node(int val) :data(val),next(NULL){}
};
void Print(Node* head)
{
  if(head==NULL) return ;
  Node* temp=head;
  do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
  cout<<head->data<<" ";
}
Node* createCircularList(vector<int> &arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < arr.size(); ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    tail->next = head;
    return head;
}
int main()
{
  vector<int> arr={20,100,40,80,60};
  Node* head=createCircularList(arr);
  Print(head);
  return 0;
}