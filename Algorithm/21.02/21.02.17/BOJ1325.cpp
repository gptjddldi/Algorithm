#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10002];
bool vis[10002];
int N, M, cnt;
vector<int> res;
int dfs(int cur){
    for(int c: graph[cur]){
        // cout<<cnt<<','<<cur<<'\n';
        if(vis[c]) continue;
        vis[c] = true;
        cnt++;
        dfs(c);
    }
    return cnt;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        cin>>v1>>v2;
        graph[v2].push_back(v1);
    }
    int maxi = 0;
    for (int i = 1; i <= N; i++)
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        vis[i] = true;
        if(dfs(i) > maxi){
            maxi = dfs(i);
            res.resize(0);
            res.push_back(i);
        }
        else if(dfs(i) == maxi){
            res.push_back(i);
        }   
    }
    sort(res.begin(), res.end());
    for(int c: res) cout<<c<<' ';
}