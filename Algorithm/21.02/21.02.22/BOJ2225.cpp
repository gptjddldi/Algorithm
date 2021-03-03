// BOJ 2225. 합분해
// dp[i][j] : j 개의 정수로 이루어진 합 i 인 경우의 수
// dp[20][1] = 1, dp[20][2] = dp[20][1] + dp[19][1] + ... + dp[1][1] = dp[20][1] + dp[19][2]
#include <bits/stdc++.h>
using namespace std;
int N, K;
int dp[201][201];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>K;
    dp[1][1] = 1;
    for (int i = 1; i <= K; i++)
    {
        dp[1][i] = i;
    }
    
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
            dp[i][j] %= 1000000000;
        }
        
    }
    cout<<dp[N][K];
}