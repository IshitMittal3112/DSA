#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
Node* Intersection(Node* A, Node* B) {
    Node* temp1 = A;
    Node* temp2 = B;

    while (temp1 != temp2) {
        temp1 = temp1 ? temp1->next : B;
        temp2 = temp2 ? temp2->next : A;
    }

    return temp1; 
}

int main()
{
  Node* head1=new Node(4);
  head1->next=new Node(1);
  
  Node* head2=new Node(5);
  head2->next=new Node(6);
  head2->next->next=new Node(1);
  head2->next->next->next=head1->next->next=new Node(8);
  head2->next->next->next->next=head1->next->next->next=new Node(5);
  head1=Intersection(head1,head2);
  cout<<head1->data;
  return 0;
}