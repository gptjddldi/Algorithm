// BOJ 1753. 최단경로
// 다익스트라
#include<bits/stdc++.h>
using namespace std;
const int MAX = 200001;
using pii = pair<int,int>;
vector<pii>ve[20001];
int dis[20001];
int V,E,st, p,c,d;
void dijkstra(){
    dis[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first, idx = cur.second;
        if(dist != dis[idx]) continue;
        for(auto nxt : ve[idx]){
            int ndis = nxt.first, nidx = nxt.second;
            if(dis[nidx] > dist+ndis){
                dis[nidx] = dist+ndis;
                pq.push({dis[nidx], nidx});
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>V>>E>>st;
    fill(dis, dis+V+1, MAX);
    for (int i = 0; i < E; i++)
    {
        cin>>p>>c>>d;
        ve[p].push_back({d,c});
    }
    dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if(dis[i] != MAX)
            cout<<dis[i]<<'\n';
        else
            cout<<"INF"<<'\n';
    }
    
}