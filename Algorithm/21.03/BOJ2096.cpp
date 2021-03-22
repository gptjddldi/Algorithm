// BOJ 2096. 내려가기
// dp[i][j] : i 행 j 열 일 때 최댓값
// dp[i][0] = max(dp[i-1][0], dp[i-1][1])+board[i][0]
// dp[i][1] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])+board[i][1]
// dp[i][2] = max(dp[i-1][1], dp[i-1][2])+board[i][2]
// 주어진 메모리가 작고, dp는 직전 값만 필요하므로 dp[10000][3] -> dp[2][3] 으로 구현해야 함
#include <bits/stdc++.h>
using namespace std;
int board[3];
int dp[2][3];
int dp2[2][3];
int N;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 3; j++){
             cin>>board[j];
        }
        dp[i%2][0] = max(dp[(i+1)%2][0], dp[(i+1)%2][1]) + board[0];
        dp[i%2][1] = max({dp[(i+1)%2][0], dp[(i+1)%2][1], dp[(i+1)%2][2]}) + board[1];
        dp[i%2][2] = max(dp[(i+1)%2][1], dp[(i+1)%2][2]) + board[2];

        dp2[i%2][0] = min(dp2[(i+1)%2][0], dp2[(i+1)%2][1]) + board[0];
        dp2[i%2][1] = min({dp2[(i+1)%2][0], dp2[(i+1)%2][1], dp2[(i+1)%2][2]}) + board[1];
        dp2[i%2][2] = min(dp2[(i+1)%2][1], dp2[(i+1)%2][2]) + board[2];
    }
        
    int ma = max({dp[(N-1)%2][0], dp[(N-1)%2][1], dp[(N-1)%2][2]});
    int mi = min({dp2[(N-1)%2][0], dp2[(N-1)%2][1], dp2[(N-1)%2][2]});

    cout<<ma<<' '<<mi;
}