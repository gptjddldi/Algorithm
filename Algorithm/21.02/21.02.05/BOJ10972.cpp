// BOJ 10972. 다음 순열
// Next Lexicographical permutation
// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm 
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int N;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		arr.push_back(k);
	}
	int m = N-1;
	while (m > 0 && arr[m-1] >= arr[m]) m--;
	if (m <= 0) {
		cout << -1;
		return 0;
	}
	int j = N-1;
	while(arr[j] <= arr[m-1]) j--;
	iter_swap(arr.begin() + m - 1, arr.begin() + j);
	reverse(arr.begin() + m, arr.end());
	for (int c : arr) cout << c<<' ';
}