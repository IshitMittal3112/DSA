#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to check if the linked list is circular
bool isCircular(Node* head) {
    if (!head) return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

// Helper function to create a circular or non-circular list
Node* createList(bool makeCircular) {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;

    if (makeCircular)
        third->next = head; // Make it circular
    else
        third->next = NULL; // Keep it linear

    return head;
}

int main() {
    Node* head = createList(true);  // Change to false to test non-circular

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}