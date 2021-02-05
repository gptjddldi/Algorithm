// BOJ 14502. 연구소

#include <bits/stdc++.h>

using namespace std;
int board[20][20];
int N, M, ret, Wn;
int dirR[4] = { 0, 1, 0, -1 };
int dirC[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> where;
vector<pair<int, int>> choice;
int bfs() {
	int cnt = 0;
	queue<pair<int, int>> q;
	int copiedBoard[20][20];
	// copy(&board[0][0], &board[0][0] + (N*M), &copiedBoard[0][0]);
	memcpy(copiedBoard, board, sizeof(board));
	for (auto c : where) q.push({ c.first, c.second });
	
	// q.push({0,0});
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int row = cur.first, col = cur.second;
		cnt++;
		for (int d = 0; d < 4; d++)
		{
			int nr = row + dirR[d], nc = col + dirC[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M ) continue;
			if(copiedBoard[nr][nc]==0){
			q.push({ nr,nc });
			copiedBoard[nr][nc] = 2;}
			// cout<<"nr: "<<nr<<" nc: "<<nc<<endl;
		}
	}
	return N * M - cnt;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) where.push_back({ i,j });
			if (board[i][j] == 1) Wn++;
			choice.push_back({ i,j });
		}
	int S = N * M;

	for (int i = 0; i < S; i++)
		for (int j = i+1; j < S; j++)
			for (int k = j+1; k < S; k++)
			{
				if (board[choice[i].first][choice[i].second] == 0 && board[choice[j].first][choice[j].second] == 0 && board[choice[k].first][choice[k].second] == 0) {
					board[choice[i].first][choice[i].second] = 1;
					board[choice[j].first][choice[j].second] = 1;
					board[choice[k].first][choice[k].second] = 1;
					Wn +=3;
					ret = max(ret, bfs()-Wn); // bfs 에서 독을 퍼뜨린 후, 독의 개수를 센 뒤, 총 길이 M*N 에서 뺀 값 리턴
					board[choice[i].first][choice[i].second] = 0;
					board[choice[j].first][choice[j].second] = 0;
					board[choice[k].first][choice[k].second] = 0;
					Wn-=3;
				}
			}
	cout << ret;
	// for(auto c: where) cout<<"x: "<<c.first<<" y: "<<c.second<<endl;
}