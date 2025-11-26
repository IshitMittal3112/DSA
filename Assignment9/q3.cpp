#include <bits/stdc++.h>
using namespace std;

struct Edge{int u,v,w;};

int findp(int x, vector<int>&p){
    if(p[x]==x) return x;
    return p[x]=findp(p[x],p);
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge> edges(e);
    for(int i=0;i<e;i++) cin>>edges[i].u>>edges[i].v>>edges[i].w;
    sort(edges.begin(),edges.end(),[](auto &a,auto &b){return a.w<b.w;});
    vector<int> p(n);
    for(int i=0;i<n;i++) p[i]=i;
    int sum=0;
    for(auto &ed:edges){
        int a=findp(ed.u,p), b=findp(ed.v,p);
        if(a!=b){
            sum+=ed.w;
            p[a]=b;
        }
    }
    cout<<sum;
}
