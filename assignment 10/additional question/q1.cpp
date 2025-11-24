#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int,int> mp;
    for (int x : a) mp[x]++;
    int bestVal = INT_MIN, bestFreq = 0;
    for (auto &p : mp) {
        int val = p.first, f = p.second;
        if (f > bestFreq) {
            bestFreq = f;
            bestVal = val;
        } else if (f == bestFreq && val > bestVal) {
            bestVal = val;
        }
    }
    cout << bestVal;
    return 0;
}
