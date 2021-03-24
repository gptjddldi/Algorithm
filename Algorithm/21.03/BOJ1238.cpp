// BOJ 1238. 파티
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAX = 200000;
int N, M, X, ret;
vector<pii> ve[1001];
int dis[1001];
int disX[1001];
void dijkstra(int st){
    dis[st] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({dis[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first, idx = cur.second;
        if(dist != dis[idx]) continue;
        for(auto nxt : ve[idx]){
            int ndist = nxt.first, nidx = nxt.second;
            if(dis[nidx] > dist + ndist){
                dis[nidx] = dist + ndist;
                pq.push({dis[nidx],nidx});
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M>>X;
    for (int i = 0; i < M; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ve[a].push_back({c,b});
    }
    fill(dis, dis+1001, MAX);
    dijkstra(X);
    copy(dis, dis+1001, disX);
    for (int i = 1; i <= N; i++)
    {
        if(i==X) continue;
        fill(dis, dis+1001, MAX);
        dijkstra(i);
        ret = max(ret, disX[i]+dis[X]); // (X -> i) + (i -> X)
    }
    cout<<ret;
}