#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data = 0) {
        this->data = data;
        this->next = NULL;
    }
};

// Print the entire list
void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert at head
void Insert_Head(Node *&head, int x) {
    Node *newnode = new Node(x);
    newnode->next = head;
    head = newnode;
}

// Insert at end
void Insertion_at_End(Node *head, int x) {
    Node *newnode = new Node(x);
    if (head == NULL) {
        head = newnode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Insert before a node
void Insertion_Before_Node(Node *&head, int target, int x) {
    if (head == NULL) return;

    if (head->data == target) {
        Insert_Head(head, x);
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node *newnode = new Node(x);
    newnode->next = curr;
    prev->next = newnode;
}

// Insert after a node
void Insertion_After_Node(Node *head, int target, int x) {
    Node *curr = head;
    while (curr != NULL && curr->data != target) {
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Target node not found.\n";
        return;
    }

    Node *newnode = new Node(x);
    newnode->next = curr->next;
    curr->next = newnode;
}

// Remove head
Node* RemoveHead(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Remove end
Node* Remove_End(Node *head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

// Remove specific node
Node* Remove_Element(Node *head, int target) {
    if (head == NULL) return NULL;

    if (head->data == target) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node not found.\n";
        return head;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;
}

// Find position of node
int Position_of_Node(Node *head, int target) {
    int position = 0;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Menu-driven interface
void Menu(Node *&head) {
    char ch;
    int x, y, pos;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "(a) Insert at beginning\n";
        cout << "(b) Insert at end\n";
        cout << "(c) Insert before/after a node\n";
        cout << "(d) Delete from beginning\n";
        cout << "(e) Delete from end\n";
        cout << "(f) Delete specific node\n";
        cout << "(g) Search for node position\n";
        cout << "(h) Display list\n";
        cout << "(q) Quit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 'a':
                cout << "Enter number to insert at head: ";
                cin >> x;
                Insert_Head(head, x);
                print(head);
                break;

            case 'b':
                cout << "Enter number to insert at end: ";
                cin >> x;
                Insertion_at_End(head, x);
                print(head);
                break;

            case 'c':
                cout << "Enter target node value: ";
                cin >> y;
                cout << "Enter number to insert: ";
                cin >> x;
                Insertion_Before_Node(head, y, x);
                Insertion_After_Node(head, y, x);
                print(head);
                break;

            case 'd':
                head = RemoveHead(head);
                print(head);
                break;

            case 'e':
                head = Remove_End(head);
                print(head);
                break;

            case 'f':
                cout << "Enter node value to delete: ";
                cin >> x;
                head = Remove_Element(head, x);
                print(head);
                break;

            case 'g':
                cout << "Enter node value to search: ";
                cin >> x;
                pos = Position_of_Node(head, x);
                if (pos != -1)
                    cout << "Position from head: " << pos + 1 << endl;
                else
                    cout << "Node not found.\n";
                break;

            case 'h':
                print(head);
                break;

            case 'q':
                cout << "Exiting program.\n";
                return;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function
int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Menu(head);
    return 0;
}