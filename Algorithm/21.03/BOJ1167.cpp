// BOJ 1167. 트리의 지름
// 임의의 지점에서 가장 먼 점 : tar 
// tar 에서 가장 먼 지점이 트리의 지름이 된다.
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ve[100002];
bool vis[1000002];
int N, p, c, d, res, tar;
void dfs(int st, int dis){
    vis[st] = true;
    for(auto a: ve[st]){
        int nxt = a.first;
        int D = a.second;
        if(vis[nxt]) continue;
        vis[nxt] = true;
        if(dis+D>res){
            tar = nxt;
            res = dis+D;
        }
        dfs(nxt, dis+D);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>p;
        while(true){
            cin>>c;
            if(c==-1) break;
            cin>>d; // a->b : c
            ve[p].push_back({c,d});
        }
    }

    
    vis[1] = true;
    dfs(1,0);
    memset(vis, false, sizeof(vis));
    vis[tar] = true;
    dfs(tar,0);
    cout<<res;
}
