// BOJ 11780. 플로이드 2
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAX = 30000000;
int n,m;
int dis[104][104]; // i->j 거리
int nxt[104][104];
void getPath(int st, int ed){
    if(st==ed){
        cout<<"0\n";
        return;
    }
    vector<int>path;
    int cur = st;
    while(cur != ed){
        path.push_back(cur);
        cur = nxt[cur][ed];
    }
    path.push_back(cur);
    cout<<path.size()<<' ';
    for(auto k : path){
        cout<<k<<' ';
    }
    cout<<'\n';
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    fill(&dis[0][0], &dis[n][n], MAX);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b] = min(c, dis[a][b]);
        nxt[a][b] = b;
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if(dis[i][j]>dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(dis[i][j]==MAX) cout<<"0 ";
            else cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            getPath(i,j);
        }
    }
    
}