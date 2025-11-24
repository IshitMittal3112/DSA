#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    for (int x : b) mp[x]--;
    bool ok = true;
    for (auto &p : mp) {
        if (p.second != 0) {
            ok = false;
            break;
        }
    }
    if (ok) cout << "true";
    else cout << "false";
    return 0;
}
