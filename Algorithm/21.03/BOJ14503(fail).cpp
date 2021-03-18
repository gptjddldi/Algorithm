// BOJ 14503. 로봇 청소기
// 북 동 남 서 // 0 1 2 3
#include <bits/stdc++.h>
using namespace std;
int N, M, r, c, d, cnt;
int board[52][52];
// int dir[4][2] = { {-1,0}, {0, -1}, {1, 0}, {0, 1} };
int dirR[4] = { -1,0,1,0 };
int dirC[4] = { 0,1,0,-1 };
// int back[4][2] = { {1,0}, {0, 1}, {-1, 0}, {0, -1} };

void dfs(int r, int c, int wa) { // wa: 보고있는 방향
	stack<pair<pair<int, int>, int>> st;
	st.push({ {r,c}, wa });
	while (!st.empty()) {
		int curR = st.top().first.first, curC = st.top().first.second;
		int curWa = st.top().second;
		cout << curR << ", " << curC << '\n';
        if(board[curR][curC]==0){
		    cnt++;
            board[curR][curC] = 2;
        }
		st.pop();
		for (int d = 0; d < 4; d++) {
			int nwa = (curWa + 3 - d) % 4;
			int nr = curR + dirR[nwa], nc = curC + dirC[nwa];
			// 현재 방향에서 왼쪽으로 4번 돌면서 확인
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (board[nr][nc] == 0) {
				st.push({ {nr,nc},nwa });
			}
		}
		
        int br = curR +dirR[(curWa + 2) % 4], bc = curC + dirC[(curWa + 2) % 4];
        if(!board[br][bc]==1)
            st.push({{br,bc},curWa});
	}


}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	dfs(r, c, d);
	cout << cnt;
}