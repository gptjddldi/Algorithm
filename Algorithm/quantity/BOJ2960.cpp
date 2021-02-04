// BOJ 2960. 에라토스테네스의 체

#include <bits/stdc++.h>
using namespace std;
int N,K;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>K;
	vector<bool> v(N+1);
	v[1] = true;
	int cnt = 0;
	for (int i = 2; i <= N; i++)
	{
		if(v[i]) continue;
		for (int j = i; j <= N; j+=i){
			if(!v[j]){
				v[j] = true; 
				cnt++;
			}
			if(cnt==K){
				cout<< j;
				break;
			}
		}
	}
}