// BOJ 1003. 피보나치 함수

#include <bits/stdc++.h>
using namespace std;
int T, N;
int z, o;
int fibo(int n) {
	if(n==0){
		z++;
		return 0;
	}
	else if(n==1){
		o++;
		return 1;
	}
	return fibo(n-1) + fibo(n-2);
}
int dp[41][2];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>T;
	dp[0][0] = 1, dp[0][1] = 0, dp[1][0] = 0, dp[1][1] = 1;
	for(int i=2; i<=40; i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
	while(T--){
		cin>>N;
		cout<< dp[N][0] <<' '<< dp[N][1]<<endl;
	}
	// 시간 초과
	// while(T--){
	// 	z = 0, o = 0;
	// 	cin>>N;
	// 	fibo(N);
	// 	cout<< z <<' '<<o<<endl;
	// }
}