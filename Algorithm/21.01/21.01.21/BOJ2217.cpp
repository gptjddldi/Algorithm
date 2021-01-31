
// BOJ 2217. 로프

#include<bits/stdc++.h>
using namespace std;

int N;
int s[100004];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> s[i];
	int res = 0;
	sort(s, s + N);
	for (int i = 1; i <= N; i++)
	{
		res = max(res, s[N - i] * i);
	}
	cout << res;
}