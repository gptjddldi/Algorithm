// BOJ 1504. 특정한 최단 경로
// 다익스트라 약간 응용
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 888888;
vector<pii> ve[900];
int dis[900];
int N, E, st,ed, p, c, d, ret;

int dijkstra(int st, int ed){
    fill(dis, dis+900, INF);
    dis[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first, idx = cur.second;
        if(dist != dis[idx]) continue;
        for(auto nxt : ve[idx]){
            int ndist = nxt.first, nidx = nxt.second;
            if(dis[nidx] > dist+ndist){
                dis[nidx] = dist+ndist;
                pq.push({dis[nidx], nidx});
            }
        }
    }
    return dis[ed];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>E;
    for (int i = 0; i < E; i++)
    {
        cin>>p>>c>>d;
        ve[p].push_back({d,c});
        ve[c].push_back({d,p});
    }
    int v1,v2;
    cin>>v1>>v2;
    ret = min((dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,N)),(dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,N)));
    if(ret>=888888) ret = -1;
    cout<<ret;
}