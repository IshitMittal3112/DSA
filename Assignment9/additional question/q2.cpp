#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> a(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    vector<vector<int>> dist(m,vector<int>(n,1e9));
    dist[0][0]=a[0][0];

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({a[0][0],0,0});

    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!pq.empty()){
        auto v=pq.top(); pq.pop();
        int d=v[0],x=v[1],y=v[2];
        if(d!=dist[x][y]) continue;
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int nd=d+a[nx][ny];
                if(nd<dist[nx][ny]){
                    dist[nx][ny]=nd;
                    pq.push({nd,nx,ny});
                }
            }
        }
    }

    cout<<dist[m-1][n-1];
}
