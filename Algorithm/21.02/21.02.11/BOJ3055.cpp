// BOJ 3055. 탈출

#include <bits/stdc++.h>
using namespace std;
int N, M;
string board[51];
int w_map[51][51], s_map[51][51];
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};
vector<pair<int,int>> water;
pair<int, int> st, ed;

void Wbfs() {
    queue<pair<int,int>> q;
    for(auto wa: water){
        q.push({wa.first, wa.second});
        w_map[wa.first][wa.second] = 1;
    }
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dirR[d], nc = c + dirC[d];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(w_map[nr][nc] || board[nr][nc]=='D' || board[nr][nc]=='X') continue;
            w_map[nr][nc] = w_map[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

void Sbfs() {
    queue<pair<int,int>> q;
    q.push({st.first, st.second});
    s_map[st.first][st.second] = 1;
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dirR[d], nc = c + dirC[d];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(board[nr][nc]=='D') {
                cout<<s_map[r][c];
                return ;
            }
            if(s_map[nr][nc] || board[nr][nc]=='X' ||(w_map[r][c]&& s_map[r][c]+1 >= w_map[nr][nc])) continue;
            
            s_map[nr][nc] = s_map[r][c] +1;
            q.push({nr,nc});
        }
        
    }
    cout<<"KAKTUS";
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    for (int i = 0; i < N; i++)
    {
        cin>>board[i];
        for (int j = 0; j < M; j++)
        {
            if(board[i][j]=='*')
                water.push_back({i,j});
            if(board[i][j]=='S')
                st = {i,j};
            if(board[i][j]=='D')
                ed = {i,j};
        }   
    }
    Wbfs();    
    Sbfs();
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout<<w_map[i][j];
    //     }
    //     cout<<'\n';
    // }
    
 
    
}