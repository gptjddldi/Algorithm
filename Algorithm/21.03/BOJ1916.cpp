// BOJ 1916. 최소 비용 구하기
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int MAX = 100000003;
int N, M, st, ed;
vector<pii> ve[1002];
int dis[1002];
void dijkstra(int s){
    dis[st] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({dis[st], st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first, idx = cur.second;
        if(dis[idx] != dist) continue;
        for(auto nxt : ve[idx]){
            int ndist = nxt.first, nidx = nxt.second;
            if(dis[nidx] > ndist + dist){
                dis[nidx] = ndist + dist;
                pq.push({dis[nidx], nidx});
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a,b,c;
    cin>>N>>M;
    for (int i = 0; i < M; i++)
    {
        cin>>a>>b>>c;
        ve[a].push_back({c,b});
    }
    cin>>st>>ed;
    fill(dis, dis+1002, MAX);
    dijkstra(st);
    cout<<dis[ed];
}