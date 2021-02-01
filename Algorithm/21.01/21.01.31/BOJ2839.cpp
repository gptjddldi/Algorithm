// BOJ 2839. 설탕 배달
#include <bits/stdc++.h>
using namespace std;

int N;
int MAX = INT_MAX-1;

int dp[5001] = {MAX, MAX, MAX, 1, MAX, 1, 2, MAX, };
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=8; i<= N; i++){
		dp[i] = min(dp[i-3]+1, dp[i-5]+1);
	}
	if(N == 4 || N == 7) cout<<-1;
	else cout<< dp[N];
}