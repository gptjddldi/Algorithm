// BOJ 2133. 타일 채우기
/*
	i 가 홀수일 때 경우의 수 0
	dp[i][0] = dp[i-2][0] + 2*dp[i-2][1]
	dp[i][1] = dp[i-2][1] + dp[i][0]

    dp[i][0] : 1*2 타일이 3개 붙은 경우
    1 1 0 0 0 0 0 0
    1 1 0 0 0 0 0 0 ...
    1 1 0 0 0 0 0 0

    dp[i][1] : 길이가 i, 시작할 때 1*2, 2*1 타일이 위 아래, 또는 아래 위로 붙은 경우
    1 1 0 0 0 0 0 0    
    1 0 0 0 0 0 0 0 ... 
    1 0 0 0 0 0 0 0    
    또는
    1 0 0 0 0 0 0 0
    1 0 0 0 0 0 0 0 ...
    1 1 0 0 0 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;

int dp[32][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	dp[2][0] = 1, dp[2][1] = 1;

	for (int i = 4; i <= N; i+=2)
	{
		dp[i][0] = dp[i - 2][0] + 2*dp[i - 2][1];
		dp[i][1] = dp[i - 2][1] + dp[i][0];

	}
    cout << dp[N][0] + 2*dp[N][1];

}