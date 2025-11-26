#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,e;
    cin>>n>>k>>e;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int> dist(n+1,1e9);
    dist[k]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,k});
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int d = top.first;
        int x = top.second;
        if(d!=dist[x]) continue;
        for(auto &p:g[x]){
            int y=p.first,w=p.second;
            if(dist[y]>d+w){
                dist[y]=d+w;
                pq.push({dist[y],y});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]==1e9){ cout<<-1; return 0; }
        ans=max(ans,dist[i]);
    }
    cout<<ans;
}
