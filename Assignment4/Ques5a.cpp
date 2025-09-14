#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Always push into non-empty queue
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    int pop() {
        if (q1.empty() && q2.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        int poppedValue;

        // If q1 has elements
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            poppedValue = q1.front();
            q1.pop();
        }
        // If q2 has elements
        else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            poppedValue = q2.front();
            q2.pop();
        }

        return poppedValue;
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20
    cout << s.pop() << endl; // 10
    cout << s.pop() << endl; // Stack is empty

    return 0;
}
