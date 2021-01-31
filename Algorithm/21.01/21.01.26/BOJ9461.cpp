// BOJ 9461. 파도반 수열

/*
	dp[i] : P(i)

	dp[0] = 1, dp[1] = 1, dp[2] = 1, 
	dp[3] = dp[0] + dp[2], 
	dp[4] = dp[3]
	dp[5] = dp[2] + dp[4], 
	dp[6] = dp[1] + dp[5], 
	dp[7] = dp[6] + dp[0],
	dp[8] = dp[7] + dp[3],
	
	=> dp[i] = dp[i-5] + dp[i-1]
*/
#include <bits/stdc++.h>
using namespace std;

vector<long long int > dp(103); // int 일 때 n=100 에서 overflow 발생
vector<int> s;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	dp[0] = 1, dp[1] = 1, dp[2] = 1, dp[3] = 2, dp[4] = 2;
	for (int i = 5; i <= 101; i++)
	{
		dp[i] = dp[i - 5] + dp[i - 1];
	}
	int N; cin >> N;
	int num;
	while (N--) {
		cin >> num; 
		s.push_back(num);
	}
	for (int c : s)
		cout << dp[c-1]<<'\n';
}