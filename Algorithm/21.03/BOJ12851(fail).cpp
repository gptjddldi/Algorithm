// BOJ 12851. 숨바꼭질 2
// bfs? dp?, 가장 빠른 시간으로 동생을 찾는 경우는 최대 3개
// dp[i*2] = min(dp[i], dp[i*2-1], dp[i*2+1])+1
#include<bits/stdc++.h>
using namespace std;
int N,K, t, cnt;
int board[200001];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>K;
    queue<int>q;
    q.push(N);
    bool flag = true;
    while(flag){
        int cur = q.front();
        q.pop();
        if(board[K] && board[cur]+1>board[K]){
            break;
        }
        for(int nxt: {cur-1, cur*2, cur+1}){
            // cout<<nxt<<'\n';
            if(nxt<0 || nxt>100002) continue;
            if(nxt==K) cnt++;
            if(board[nxt] && board[nxt]<board[cur]+1) continue;
            board[nxt] = board[cur] + 1;
            q.push(nxt);
        }

    }
    if(N==K) cout<<0<<'\n'<<1;
    else cout<<board[K]<<'\n'<<cnt;
}