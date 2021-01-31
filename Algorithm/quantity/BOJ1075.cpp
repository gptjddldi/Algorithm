// BOJ 1075. 나누기
#include <bits/stdc++.h>
using namespace std;
long long N;
int F, res;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>F;
	int K = (N / 100) * 100;
	for (int i = K; i < K + 100; i++)
	{
		if(i % F == 0) {
			if(i%100 < 10) cout<<'0';
			cout<<i % 100;
			break;
		}
	}
	
}