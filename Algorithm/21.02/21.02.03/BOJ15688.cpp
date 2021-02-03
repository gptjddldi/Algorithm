// BOJ 15688. 수 정렬하기 5
// Count Sort
#include <bits/stdc++.h>
using namespace std;
int N;
// int arr[2000004];
int cnt[2000004];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	int a;
	for (int i = 0; i < N; i++) {
		cin>>a;
		cnt[a+1000000]++;
	}
	for (int i = 0; i <= 2000000; i++)
		while(cnt[i]--)
			cout<<i-1000000<<'\n';
}