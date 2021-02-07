// BOJ 6593. 상범빌딩

#include <bits/stdc++.h>
using namespace std;
int dirR[6] = { 0, 1, 0, -1, 0, 0 };
int dirC[6] = { 1, 0, -1, 0, 0, 0 };
int dirH[6] = { 0, 0, 0, 0, 1, -1 };
char bd[31][31][31];
int t[31][31][31];
int L, N, M;
void bfs(int r, int c, int h) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ h, {r,c} });
	t[h][r][c] = 1;
	while (!q.empty()) {
		int curR = q.front().second.first, curC = q.front().second.second, curH = q.front().first;
		q.pop();
		if (bd[curH][curR][curC] == 'E') {
			cout << "Escaped in " << t[curH][curR][curC]-1 << " minute(s)." << '\n';
			return;
		}
		for (int d = 0; d < 6; d++)
		{
			int nr = curR + dirR[d], nc = curC + dirC[d], nh = curH + dirH[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || nh < 0 || nh >= L) continue;
			if (t[nh][nr][nc] || bd[nh][nr][nc]=='#') continue;
//			if (bd[nh][nr][nc] == '#' || bd[nh][nr][nc]=='.') {
//			cout << "nh : " << nh << " nr : " << nr << " nc : " << nc << " bd : " << (char)bd[nh][nr][nc] << '\n';
				t[nh][nr][nc] = t[curH][curR][curC] + 1;
				q.push({ nh, {nr,nc} });
//			}
		}

	}
	cout << "Trapped!" << '\n';
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while (true) {
		cin >> L >> N >> M; // 층 행 렬
		if (!L && !N && !M) break;
		memset(bd, 0, sizeof(bd));
		memset(t, 0, sizeof(t));
		int r= 0, c = 0, h = 0;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					cin >> bd[i][j][k]; // i층 j행
					if (bd[i][j][k] == 'S') {
						r = j, c = k, h = i;
					}
				}

			}

		}
		bfs(r, c, h);
	}
}