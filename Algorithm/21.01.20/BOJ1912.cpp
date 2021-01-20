//BOJ 1912. 연속합

#include <bits/stdc++.h>
using namespace std;

int arr[100004];
int d[1000004];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	d[1] = arr[1];
	for (int i = 2; i <= N; i++) d[i] = max(d[i - 1], 0) + arr[i];
	cout << *max_element(d + 1, d + N + 1);
}