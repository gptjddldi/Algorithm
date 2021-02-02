// BOJ 9251. LCS (Longest Common Subsequence)

#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int dp[2][1003];
// dp[i][j] s1 의 i 번째, s2의 j 번째까지 탐색했을 때 길이의 최댓값
// s1[i] == s2[j] : dp[i][j] =  dp[i-1][j-1]+1
// else : dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// dp[i][j], dp[i-1][j] 만 필요하므로 dp[2][1003] 으로도 구현가능
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>s1>>s2;
	for (int i = 0; i < s1.size(); i++)
	{
		int k = i % 2;
		int l = (i+1) % 2;
		for (int j = 0; j < s2.size(); j++)
		{
			if(s1[i]==s2[j]){
				dp[k][j] = dp[l][j-1] + 1;
			}
			else dp[k][j] = max(dp[l][j], dp[k][j-1]);
		}
		
	}
	cout<<dp[(s1.size()-1)%2][s2.size()-1];
}