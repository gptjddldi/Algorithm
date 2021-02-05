// BOJ 2468. 안전 영역
#include <bits/stdc++.h>
using namespace std;
int board[103][103];
// bool watered[103][103];
bool vis[103][103];
int dirR[4] = { 0,1,0,-1 };
int dirC[4] = { 1,0,-1,0 };
int N, high, ret;

void dfs(int h, int r, int c) {
	vis[r][c] = true;
	for (int d = 0; d < 4; d++)
	{
		int nr = r + dirR[d];
		int nc = c + dirC[d];
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (board[nr][nc] <= h || vis[nr][nc]) continue;
		dfs(h, nr, nc);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			high = max(board[i][j], high);
		}
	for (int h = 0; h <= high; h++)
	{
		int cnt = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!vis[i][j] && board[i][j] > h) {
					dfs(h, i, j);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret;
}