//  BOJ 9465. 스티커
// dp[0][i], dp[1][i] 0, 1 열 i 행 스티커를 선택했을 때 최댓값

#include<bits/stdc++.h>
using namespace std;
int T, n, board[2][100002];
int dp[2][100002];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cin>>board[j][i];
            }    
        }
        dp[0][0] = board[0][0], dp[0][1] = board[0][1];
        dp[1][0] = board[1][0], dp[1][1] = board[1][1];
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + board[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + board[1][i];

        }
        
        cout<<max(dp[0][n-1], dp[1][n-1])<<'\n';
    }
    
}