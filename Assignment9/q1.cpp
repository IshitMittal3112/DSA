#include <bits/stdc++.h>
using namespace std;

int main() {
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    cin>>s;
    vector<int> vis(v,0);
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x=q.front(); q.pop();
        cout<<x<<" ";
        for(int y:g[x]){
            if(!vis[y]){
                vis[y]=1;
                q.push(y);
            }
        }
    }
}
