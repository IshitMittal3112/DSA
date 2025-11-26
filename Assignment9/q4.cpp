#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>> g(n);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int sum=0;
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        int w = p.first;
        int x = p.second;
        if(vis[x]) continue;
        vis[x]=1;
        sum+=w;
        for(auto &p:g[x]){
            if(!vis[p.first]) pq.push({p.second,p.first});
        }
    }
    cout<<sum;
}
