#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int target;
    cin >> target;
    unordered_set<int> st;
    bool ok = false;
    for (int x : a) {
        int need = target - x;
        if (st.count(need)) {
            ok = true;
            break;
        }
        st.insert(x);
    }
    if (ok) cout << "true";
    else cout << "false";
    return 0;
}
