// BOJ 11727. 2*n 타일링 2

#include <bits/stdc++.h>
using namespace std;

long long dp[1004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	dp[1] = 1, dp[2] = 3;
	for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] % 10007 + (dp[i - 2] * 2) % 10007;
	cout << dp[N]%10007;
}