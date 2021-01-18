// BOJ 1236. 성 지키기
#include<bits/stdc++.h>

using namespace std;
char castle[255][255];
bool col[4], row[4];
int C, R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> R;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++) {
			cin >> castle[i][j];
			if (castle[i][j] == 'X') {
				col[i] = true;
				row[j] = true;
			}
		}

	for (auto c : col)
		if (c == false)
			cnt1++;
	for (auto r : row)
		if (row == false)
			cnt2++;
	int res = max(cnt1, cnt2);
	cout << res;
}