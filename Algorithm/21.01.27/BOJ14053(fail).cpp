// BOJ 14503. 로봇 청소기

#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[50][50];

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북 동 남 서 / 위 오른 아래 왼
int curX, curY, D; //(x,y), 방향

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> curX >> curY >> D;
	int cnt = 0;
	stack<pair<pair<int, int>,int>> dfs;
	for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
		    cin >> board[i][j];
		
	
	dfs.push({{ curX,curY },D});
		
	while (!dfs.empty()) {
		int row = dfs.top().first.first;
		int col = dfs.top().first.second;
		dfs.pop();
		if (board[row][col] == 0) {
			board[row][col] = 2;
			cnt++;
		}
        bool flag = false;
		for (int i = 0; i < 4; i++)
		{
            int nextDir = (D+(3-i)) % 4;
			int nr = row + dir[nextDir][0];
			int nc = col + dir[nextDir][1];
			if (board[nr][nc] == 0) {
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				dfs.push({{ nr, nc },nextDir});
                flag = true;
                break;
			}
		}
        if(!flag){
            int backR = row - dir[D][0];
            int backC = col - dir[D][1];
            if(backR < 0 || backR >= N || backC<0 || backC >= M || board[backR][backC]==1) break;
            dfs.push({{backR, backC},D});
        }
	}

	cout << cnt;
}
/*
		if(바라보는 방향의 왼쪽 == 0) : row, col 위치 이동하고, cnt++, stack에 넣음, board[][]=2
		else : 왼쪽으로 한 번 더 돎
		네 방향 모두 돌았는데 청소할 곳 없으면 후진,
		후진했을 때 board 값이 1이라면 break, return cnt
		*/