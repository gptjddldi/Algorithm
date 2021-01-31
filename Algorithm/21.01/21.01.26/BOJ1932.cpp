// BOJ 1932. 정수 삼각형

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> dp(503, vector < int>(503));
vector<vector<int>> s(503, vector < int>(503));

int fn(int i, int j) {
	if (j < 0) j++;
	if (j > i) j--;
	return dp[i][j];
}

int maxSum(vector < vector<int>>& s) {
	// dp[i][j] : i 행, j열 골랐을 때의 최댓값
	// dp[i][j] = s[i][j] + max(dp[i-1][j-1], max(dp[i-1][j]);
	dp[0][0] = s[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = s[i][j] + max(fn(i - 1, j - 1), fn(i - 1, j));
//			cout << dp[i][j]<<' ';
		}
//		cout << '\n';
	}
	return *max_element(dp[N - 1].begin(), dp[N - 1].end());
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)	cin >> s[i][j];
	}
	cout << maxSum(s);
}