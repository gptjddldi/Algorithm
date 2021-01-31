// BOJ 2583. 영역 구하기

#include<bits/stdc++.h>
using namespace std;
int board[103][103];
int M, N, K;
int x1, x2, y2, y3;
int cnt;
vector<int> res;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dfs(int x, int y) {
	cnt++;
	board[x][y] = cnt;
	for (int i = 0; i < 4; i++)
	{
		int nxtX = x + dx[i];
		int nxtY = y + dy[i];
		if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
		if (board[nxtX][nxtY]) continue;
		dfs(nxtX, nxtY);
	}
	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> M >> N >> K;
	while (K--) {
		cin >> x1 >> y2 >> x2 >> y3;
		for (int x = x1; x < x2; x++)
			for (int y = y2; y < y3; y++) {
				board[x][y] = -1;
			}
	}
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
		{
			if (board[x][y] == 0) {
				cnt = 0;
				dfs(x, y);
				res.push_back(cnt);
			}
		}


	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int c : res) cout << c << ' ';

}