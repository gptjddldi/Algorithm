// BOJ 9095. 1,2,3 더하기

#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> T(20);
int d[15];
int posSum(int k) {
	for (int i = 4; i <= k; i++) {
		d[i] = d[i - 3] + d[i - 2] + d[i - 1];
	}
	return d[k];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[1] = 1, d[2] = 2, d[3] = 4;
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> T[i];
	T.resize(N);
	for (int k : T) cout << posSum(k)<<'\n';
}