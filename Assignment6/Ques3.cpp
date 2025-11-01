#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(int data1) {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};
Node* Arr_DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* back = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], NULL, back);
        back->next = temp;
        back = temp;
    }
    return head;
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
int count_CLL(Node* head)
{
  int cnt=1;
  if(!head) return 0;
  Node* temp=head->next;
  while(temp!=head)
  {
    cnt++;
    temp=temp->next;
  }
  return cnt;
}
int count_DLL(Node* head)
{
  int cnt=0;
  Node* temp=head;
  while (temp!=NULL)
  {
    cnt++;
    temp=temp->next;
  }
  return cnt;
}
int main()
{
  vector<int> arr={20,100,40,80,60};
  Node* head=Arr_DLL(arr);
  int count=count_DLL(head);
  cout<<"Number of Elements in DLL:"<<count<<endl;
  vector<int> arrr={20,100,40,80,60,23};
  head=createCircularList(arrr);
  count=count_CLL(head);
  cout<<"Number of Elements in CLL:"<<count<<endl;
  return 0;
}