#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) { data = x; next = NULL; }
};

Node* buildList(int n) {
    if (n == 0) return NULL;
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main() {
    int n1, n2;
    cin >> n1;
    Node* head1 = buildList(n1);
    cin >> n2;
    Node* head2 = buildList(n2);

    unordered_set<int> s1, s2;
    Node* cur = head1;
    while (cur) {
        s1.insert(cur->data);
        cur = cur->next;
    }
    cur = head2;
    while (cur) {
        s2.insert(cur->data);
        cur = cur->next;
    }

    vector<int> inter, uni;
    for (int x : s1) {
        if (s2.count(x)) inter.push_back(x);
    }
    unordered_set<int> su = s1;
    for (int x : s2) su.insert(x);
    for (int x : su) uni.push_back(x);

    cout << "Intersection List: ";
    for (int i = 0; i < inter.size(); i++) {
        if (i) cout << " ";
        cout << inter[i];
    }
    cout << "\nUnion List: ";
    for (int i = 0; i < uni.size(); i++) {
        if (i) cout << " ";
        cout << uni[i];
    }
    return 0;
}
