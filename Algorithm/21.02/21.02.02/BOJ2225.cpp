// BOJ 2225. 분해

#include <bits/stdc++.h>
using namespace std;
int dp[202][202];
int N,M;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	dp[1][1] = 1; dp[2][1] = 1;
	for (int i = 0; i < 201; i++)
	{
		dp[1][i] = i;
	}
	
	for (int i = 2; i <= N; i++)
	{
		dp[i][1] = 1;
		for (int j = 2; j <= M; j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
			dp[i][j] = dp[i][j] % 1000000000;
		}
		
	}
	cout<<dp[N][M];
}