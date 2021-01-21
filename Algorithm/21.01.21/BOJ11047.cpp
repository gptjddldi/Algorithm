// BOJ 11047. 동전 0

#include <bits/stdc++.h>
using namespace std;

int n, k;
int s[11];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	int num = 0;
	for (int i = n - 1; i >= 0; i--) {
		num += k / s[i]; // 몫
		k = k % s[i]; //나머지

	}
	cout << num;
}