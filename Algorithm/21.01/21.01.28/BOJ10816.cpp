// 10816 숫자 카드 2
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	vector<int>res;
	cin >> N;
	int k;
	while (N--) {
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	cin >> M;
	while (M--) {
		cin >> k;
		res.push_back(upper_bound(v.begin(), v.end(), k) - lower_bound(v.begin(), v.end(), k));
	}
	for (int c : res) cout << c << ' ';
}