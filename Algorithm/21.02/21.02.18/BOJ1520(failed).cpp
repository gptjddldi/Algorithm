// BOJ 1520. 내리막 길
// dp[i][j] : i,j 위치까지 도달할 수 있는 경우의 수
// dp[i][j] = dp[i-1][j] + dp[i][j-1] (각각은 dp[i][j] 보다 클 때)
#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,board[501][501], dp[501][501];
// bool vis[501][501];
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};
// void dfs(int r, int c, int num){
//     if(r==n-1 && c==m-1) {
//         cnt++;
//         return;
//     }
//     for (int d = 0; d < 4; d++)
//     {
//         int nr = r + dirR[d], nc = c + dirC[d];
//         if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
//         if(board[nr][nc]>=board[r][c]) continue;
//         // cout<<nr<<','<<nc<<'\n';
//         // vis[nr][nc] = true;
//         dfs(nr,nc,board[nr][nc]);
//     }
    
// }

void toGo(int r, int c){

    dp[r][c]
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>n>>m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>board[i][j];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(!i&&!j) continue;
            if(!i){
                if(board[i][j-1]>board[i][j])
                    dp[i][j] += dp[i][j-1];
                // cout<<i<<','<<j<<" : "<<dp[i][j]<<'\n';
            }
            if(!j){
                if(board[i-1][j]>board[i][j])
                    dp[i][j] += dp[i-1][j];
            }
            if(i&&j){
                if(board[i-1][j]>board[i][j])
                    dp[i][j] += dp[i-1][j];
                if(board[i][j-1]>board[i][j])
                    dp[i][j] += dp[i][j-1];
            }
            cout<<i<<','<<j<<" : "<<dp[i][j]<<'\n';
    
        } 
    }
    
    // dfs(0,0,board[0][0]);
    cout<<dp[n-1][m-1];
}