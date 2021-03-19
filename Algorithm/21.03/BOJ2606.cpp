// BOJ 2606. 바이러스
// 그래프, 탐색

#include <bits/stdc++.h>
using namespace std;
vector<int> graph[102];
int vis[102];
int N, M, cnt;
void dfs(int cur){
    // cout<<cur<<' '<<'\n';
    for(int nxt: graph[cur]){
        if(vis[nxt]) continue;
        cnt++;
        vis[nxt] = true;
        dfs(nxt);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis[1] = true;
    dfs(1);
    cout<<cnt;
}