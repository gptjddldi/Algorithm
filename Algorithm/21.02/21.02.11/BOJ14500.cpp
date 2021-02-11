// BOJ 14500. 테트로미노

#include <bits/stdc++.h>
using namespace std;
int N, M, res = 0;
int board[502][502];
bool vis[502][502];
int dirR[4] = {0, 1, 0, -1};
int dirC[4] = {1, 0, -1, 0};
vector<pair<int, int>> h_shape[4] ={
    {{-1,0}, {0,0}, {0, 1}, {0, -1}}, //ㅗ
    {{1,0}, {0,0}, {0, 1}, {0, -1}}, // ㅜ
    {{-1,0}, {0,0}, {1, 0}, {0, 1}}, // ㅏ
    {{-1,0}, {0,0}, {1, 0}, {0, -1}}, // ㅓ

} ;
void dfs(int r, int c, int cnt, int ret){
    if(cnt == 4){
        // cout<<ret<<',';
        res = max(ret, res);
        return ;
    }
    
    for (int d = 0; d < 4; d++)
    {
        int nr = r + dirR[d], nc = c + dirC[d];
        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        if(vis[nr][nc]) continue;
        vis[nr][nc] = 1;
        dfs(nr, nc, cnt+1, ret + board[nr][nc]);    
        vis[nr][nc] = 0;
    }
    if(cnt==0){
        for (int i = 0; i < 4; i++)
        {
            int k = 0, re = 0;
            for (int d = 0; d < 4; d++)
            {
                int nr = r + h_shape[i][d].first, nc = c + h_shape[i][d].second;
                if(nr<0 || nr>=N || nc<0 || nc>=M) break;
                // if(vis[nr][nc]) break;
                re += board[nr][nc];
                k++;
            }
            res = max(res, re);
        }
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin>>board[i][j];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dfs(i, j, 0, 0);
            memset(vis, 0, N*M);
        }
        
    }
    cout<<res;
}