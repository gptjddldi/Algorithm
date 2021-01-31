// BOJ 11057. 오르막 수
/*
	dp[i][j]
	길이 i, 마지막 수가 j일 때의 경우의 수
	ex) dp[5][7] => ____7 이때 4번째 자리에 올 수 있는 경우를 계산하면 됨
	dp[5][7] = dp[4][0] + dp[4][1] + ... + dp[4][7] 이고 이때 dp[4][0] ~ dp[4][6] = dp[5][6]
	
	dp[i][j] = dp[i][j-1] + dp[i-1][j]

	-----

	길이 i의 수가 j로 끝나면, 그 경우의 수는 길이 i-1의 수가 j로 끝나는 경우와 
	(dp[i-1][j] 의 경우 맨 뒤에 j를 추가한다는 느낌)
	길이 i의 수가 j-1 로 끝나는 경우의 수의 합임 
	(dp[i][j-1] 의 마지막 수를 j로 바꾼다고 생각하면 이해될 수도)

*/
#include <bits/stdc++.h>
using namespace std;
long long dp[1004][10];
// dp[N+1][9];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	fill(&dp[1][0], &dp[1][10], 1);
	int N;
	cin >> N;

	for (int i = 1; i <= N+1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j] % 10007 + dp[i][j - 1] % 10007;
			}
			dp[i][j] = dp[i][j] % 10007 ;

		}
	}

	cout << dp[N + 1][9];
}