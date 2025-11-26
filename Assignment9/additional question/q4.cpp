#include <bits/stdc++.h>
using namespace std;

int m,n;
vector<vector<int>> a;
vector<vector<int>> vis;

void dfs(int x,int y){
    if(x<0||y<0||x>=m||y>=n) return;
    if(a[x][y]==0||vis[x][y]) return;
    vis[x][y]=1;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int main(){
    cin>>m>>n;
    a.assign(m,vector<int>(n));
    vis.assign(m,vector<int>(n,0));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int c=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1 && !vis[i][j]){
                c++;
                dfs(i,j);
            }
        }
    }
    cout<<c;
}
