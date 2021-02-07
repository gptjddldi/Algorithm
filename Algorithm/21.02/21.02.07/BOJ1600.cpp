// BOJ 1600. 말이 되고픈 원숭이

#include <bits/stdc++.h>
using namespace std;
int K, M, N; // M : 열의 길이, N: 행의 길이
bool board[203][203];
bool vis[203][203][31];
int mon_R[4] = {0,1,0,-1};
int mon_C[4] = {1,0,-1,0};
int hor_R[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int hor_C[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int bfs(){
    queue<pair<pair<int,int>,pair<int,int>>> q; //q.front().first : {r,c},  q.front().second : K, distance
    q.push({{0,0},{0,0}});
    vis[0][0][0] = true;

    while(!q.empty()){
        int curR = q.front().first.first, curC = q.front().first.second; 
        int curK = q.front().second.first, cnt = q.front().second.second;
        q.pop();

        // cout<<curR<<", "<<curC<<" : vis = "<<vis[curR][curC]<<'\n';
        if(curR == N-1 && curC == M-1) return cnt;

        // 말의 움직임 히이이이이잉
        if(curK < K){
            for (int d = 0; d < 8; d++){
                // cout<<"<><><>"<<'\n';
                int nr = curR + hor_R[d], nc = curC + hor_C[d];
                if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
                if(vis[nr][nc][curK+1] || board[nr][nc]) continue;
                vis[nr][nc][curK+1] = true;
                q.push({{nr, nc},{curK+1, cnt+1}});
            }
        }

        // 원숭이의 움직임
        for (int d = 0; d < 4; d++){
            int nr = curR + mon_R[d], nc = curC + mon_C[d];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(vis[nr][nc][curK] || board[nr][nc]) continue;
            vis[nr][nc][curK] = true;
            q.push({{nr, nc},{curK, cnt+1}});
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>K>>M>>N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin>>board[i][j];        
    cout<<bfs();    
    
}