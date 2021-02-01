// BOJ 1788. 피보나치 수의 확장

#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000002];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= abs(N); i++) {
		dp[i] = (dp[i-1] % 1000000000) + (dp[i-2] % 1000000000);
		dp[i] %= 1000000000;
	}
	
	if(N< 0) {
		if(N%2 == 0) cout<<-1<<'\n'<<dp[abs(N)];
		else cout<<1<<'\n'<< dp[abs(N)];
	}
	else if(N>0){
		cout<<1<<'\n'<<dp[N];
	}
	else cout<< 0 << endl << 0;
}