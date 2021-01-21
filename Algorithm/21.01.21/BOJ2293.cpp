// BOJ 2293. 동전 1

#include <bits/stdc++.h>
using namespace std;

int n, k;
int s[105];
vector<int> d1;
vector<int> d2;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	d1.resize(k + 1);
	d2.resize(k + 1);
	for (int i = 0; i < n; i++)	cin >> s[i];
	for (int t = 0; t <= k; t += s[0]) d1[t] = 1;
	for (int i = 1; i < n; i++)
	{
		fill(d2.begin(), d2.end(), 0);
		for (int j = 0; j <= k; j++)
		{
			d2[j] = j >= s[i] ? d1[j] + d2[j - s[i]] : d1[j];
		}
		d1 = d2;
	}

	cout << d1[k];
}