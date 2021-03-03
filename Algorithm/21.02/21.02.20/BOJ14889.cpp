// BOJ 14889. 스타트와 링크
#include <bits/stdc++.h>
using namespace std;
int N, mini= 1000000;
int board[21][21], team[21];
bool isused[21];

int get_capability(int pos, int dif, int idx){
    for (int i = 0; i <= pos; i++)
    {
        dif += board[team[i]][idx] + board[idx][team[i]];
    }
    return dif;
}

void bt(int pos, int idx, int dif){
    int S = 0, S2 = 0;
    if(pos==N/2){
        for (int i = 0; i < N; i++)
            if(!isused[i]){
                for (int j = 0; j < N; j++)
                    if(!isused[j]) 
                    S += board[i][j];
                
            }

        mini = min(mini, abs(S-dif));
        return ;
    }

    for (int i = idx; i < N; i++)
    {
        if(!isused[i]){
            isused[i] = true;
            team[pos] = i;
            bt(pos+1, i, get_capability(pos, dif, i));
            isused[i] = false;
        }
    }
    
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin>>board[i][j];
        } 
    }
    bt(0,0,0);
    cout<<mini;
}