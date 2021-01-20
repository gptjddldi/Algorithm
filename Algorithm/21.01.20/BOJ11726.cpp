// BOJ 11726. 2*n 타일링

#include <bits/stdc++.h>
using namespace std;
int d[1004];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	d[0] = 1, d[1] = 2;
	cin >> N;
	for (int i = 2; i < N; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] = d[i] % 10007;
	}
	cout <<d[N-1];
}