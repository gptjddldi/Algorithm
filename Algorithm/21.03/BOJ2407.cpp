// BOJ 2407. 조합
// next_permutation 을 이용하는 방식은 이해를 못하겠음
// dp : nCr = n-1Cr + n-1Cr-1
// + BigNumAdd function
#include<bits/stdc++.h>

using namespace std;
int arr[103];
bool used[103];
string dp[102][102]; // dp[i][j] : iCj dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
int n, m, cnt;
string bigNumAdd(string s1, string s2){
	long long sum = 0;
	string ret;
	// 1의 자리부터 더하기 시작
	while(!s1.empty() || !s2.empty() || sum){
		if(!s1.empty()){
			sum += s1.back()-'0';
			s1.pop_back();
		}
		if(!s2.empty()){
			sum += s2.back()-'0';
			s2.pop_back();
		}
		ret.push_back((sum%10) +'0');
		sum/=10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}
string combination(int n, int r){
	
	if(n==r || r==0) return "1";
	string &res = dp[n][r];
	if(res!="") return res;
	res = bigNumAdd(combination(n-1,r), combination(n-1,r-1));
	return res;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cout<<combination(n,m);
}