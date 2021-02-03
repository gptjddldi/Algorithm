// BOJ 1476. 날짜 계산

#include <bits/stdc++.h>
using namespace std;
int E, S, M;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>E>>S>>M;
	int i,j,k;
	int ret = 1;
	while(E!=1 || S!=1 || M!=1){
		E--,S--,M--;
		if(E==0) E = 15;
		if(S==0) S = 28;
		if(M==0) M = 19;
		ret ++;
	}
	cout<<ret;
}