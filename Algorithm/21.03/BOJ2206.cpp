// BOJ 2206. 벽 부수고 이동하기
#include <bits/stdc++.h>
using namespace std;
int N,M, ret;
char board[1004][1004];
int dis[1004][1004][2]; 
// dis[i][j][0] : 벽 안부수고 (i,j) dis[i][j][1]: 벽 부수고 (i,j)

int dirR[4] = {1,0,-1,0};
int dirC[4] = {0,1,0,-1};

void bfs(int r, int c){
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c},0});
    dis[r][c][0] = 1;

    while(!q.empty()){
        int curR = q.front().first.first, curC = q.front().first.second;
        int b = q.front().second;
        q.pop();
        // cout<<curR<<", "<<curC<<": "<<dis[curR][curC][b]<<'\n';
        for (int d = 0; d < 4; d++)
        {
            int nr = curR + dirR[d], nc = curC + dirC[d];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(board[nr][nc]=='1' && b==0 && dis[nr][nc][1]==0){
                q.push({{nr,nc},1});
                dis[nr][nc][1] = dis[curR][curC][b] + 1;
            }
            else if(board[nr][nc]=='0' && dis[nr][nc][b]==0){
                q.push({{nr,nc},b});
                dis[nr][nc][b] = dis[curR][curC][b] +1;
            }
        }
        
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>board[i][j];
        
        }
    }
    bfs(0,0);
    // int ret = dis[N-1][M-1][0];
    // if(ret==0){
    //     ret = dis[N-1][M-1][1];
    // } else if(dis[N-1][M-1][1]==0) ;
    // else ret = min(dis[N-1][M-1][1], dis[N-1][M-1][0]);

    
    // cout<<dis[N-1][M-1][1];
    if(dis[N-1][M-1][0]==0 && dis[N-1][M-1][1]==0) ret = -1;
    else if(dis[N-1][M-1][0] && dis[N-1][M-1][1]) ret = min(dis[N-1][M-1][1],dis[N-1][M-1][0]);
    else ret = max(dis[N-1][M-1][1],dis[N-1][M-1][0]);

    cout<<ret;
}