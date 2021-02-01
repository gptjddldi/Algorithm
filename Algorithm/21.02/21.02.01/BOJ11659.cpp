// BOJ 11659. 구간 합 구하기

#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> v;
int arr[100002];
vector<int> res;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M;
	int k;
	for (int i = 1; i <= N; i++)
	{
		cin>>k;
		arr[i] = arr[i-1] + k;
	}
	
	while(M--){
		int i, j;
		cin>>i>>j;
		res.push_back(arr[j]-arr[i-1]);
	}
	for(int c: res) cout<<c<<'\n';
}