// BOJ 4485. 녹색 옷 입은 애가 젤다지?
// dijkstra + bfs
#include <bits/stdc++.h>
using namespace std;
using piii = pair<pair<int,int>,int>;
const int MAX = 8888888;
int N, cnt;
int board[150][150];
int dis[150][150];
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};

int dijkstra(){
    dis[0][0] = board[0][0];
    priority_queue<piii,vector<piii>, greater<piii>> pq;
    pq.push({{0,0},dis[0][0]});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int r = cur.first.first, c = cur.first.second, dist = cur.second;
        if(dist != dis[r][c]) continue;
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dirR[d], nc = c + dirC[d];
            if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
            if(dis[nr][nc] > board[nr][nc] + dist){
                dis[nr][nc] = board[nr][nc] + dist;
                pq.push({{nr,nc},dis[nr][nc]});
            }
        }
        
    }

    return dis[N-1][N-1];
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    while(N){
        fill(&dis[0][0], &dis[150][150], MAX);
        // memset(dis, 0, sizeof(dis));
        memset(board, 0, sizeof(board));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin>>board[i][j];
            }
            
        }
        cout<<"Problem "<<++cnt<<": "<<dijkstra()<<'\n';
        cin>>N;
    }
}