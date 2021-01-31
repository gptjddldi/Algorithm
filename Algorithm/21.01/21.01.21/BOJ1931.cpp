// BOJ 1931. 회의실 배정

#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> pa(100004);

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second== b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	pa.resize(N);
	for (int i = 0; i < N; i++)	cin >> pa[i].first >> pa[i].second;
	sort(pa.begin(), pa.end(), compare);
	int cnt = 0;
	int st = 0, end = 0;
	for (auto c : pa) {
		if (c.first >= end) {
			st = c.first, end = c.second;
			cnt++;
		}
	}
	cout << cnt;
}