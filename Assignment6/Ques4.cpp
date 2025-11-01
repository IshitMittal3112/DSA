#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }
    Node(char data1) {
        data = data1;
        next = NULL;
        prev = NULL;
    }
};
Node* Arr_LL(string arr) {
    Node* head = new Node(arr[0]);
    Node* back = head;
    for (int i = 1; i < arr.length(); i++) {
        Node* temp = new Node(arr[i], NULL, back);
        back->next = temp;
        back = temp;
    }
    return head;
}
bool checkPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* left = head;
    Node* right = head;

    
    while (right->next)
        right = right->next;
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }

    return true;
}

int main() {
    string ch = "level"; 
    Node* head = Arr_LL(ch);

    if (checkPalindrome(head))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}