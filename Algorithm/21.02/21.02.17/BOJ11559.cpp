//BOJ 11559. 뿌요뿌요
// (r,c) 가 터진다 -> board[r][c] = board[r][c-1]
// 한 사이클 돌고 한번에 터져야 함
#include <bits/stdc++.h>
using namespace std;
char board[12][6];
bool vis[12][6];
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};
vector<pair<int,int>> color;
vector<pair<int,int>> color2;
int ret, cnt;

void bfs(int curR, int curC){
    // cout<<curR<<','<<curC;
    int count = 1;
    queue<pair<int, int>> q;
    q.push({curR, curC});
    vis[curR][curC] = true;
    color2.push_back({curR, curC});
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dirR[d], nc = c + dirC[d];
            if(nr<0 || nr>=12 || nc<0 || nc>=6) continue;
            if(vis[nr][nc]) continue;
            if(board[nr][nc] == board[r][c]){
                // cout<<curR<<','<<curC<<"<><><><>"<<nr<<','<<nc<<'\n';
                count++;
                // cout<<"<<<<"<<count;
                vis[nr][nc] = true;
                q.push({nr,nc});
                color2.push_back({nr, nc});
            }    
        }
    }
    if(count<4){
        for (int i = 0; i < count; i++)
        {
            color2.pop_back();
        }
        return;
    }
    cnt++;
}

void boomb(){
    for(auto c: color2){
        if(c.first==0) continue;
        // cout<<c.first<<',';
        for (int r = c.first; r >= 1; r--)
        {
            board[r][c.second] = board[r-1][c.second];
        }
        board[0][c.second] = '.';
        
    }
    color2.resize(0);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++) {
            cin>>board[i][j];
            // if(board[i][j]!='.'){
            //     color.push_back({i,j});
            // }
        }

    do{
        cnt = 0;
        memset(vis, 0, sizeof(vis));

        for (int r = 0; r < 12; r++)
            for (int c = 0; c < 6; c++)
            {
                if(vis[r][c] || board[r][c]=='.') continue;
                bfs(r,c);
            }
        boomb();
        if(cnt)
            ret++;  
    } while (cnt!=0);
    // bfs(10,3);

    // for (int r = 0; r < 12; r++)
    // {
    //     for (int c = 0; c < 6; c++)
    //     {
    //         cout<<board[r][c];
    //     }
    //     cout<<'\n';
    // }
    
    cout<<ret;
}


