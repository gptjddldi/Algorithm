// BOJ 2051. 약수 구하기

#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> v;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
    cin>>N>>K;
	for (int i = 1; i * i <= N; i++)
	{
		if(N%i == 0){
			if(i*i==N) v.push_back(i);
			else{
			v.push_back(i);
			v.push_back(N/i);
        
		}
		}
	}
	sort(v.begin(), v.end());
	if(v.size() <= K-1) cout<<0;
	else cout<<v[K-1];
}