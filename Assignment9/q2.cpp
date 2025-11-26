#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int x){
    vis[x]=1;
    cout<<x<<" ";
    for(int y:g[x]){
        if(!vis[y]) dfs(y);
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    g.resize(v);
    vis.assign(v,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int s;
    cin>>s;
    dfs(s);
}
