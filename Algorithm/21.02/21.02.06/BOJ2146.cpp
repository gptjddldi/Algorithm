// BOJ 2146. 다리 만들기

#include <bits/stdc++.h>
using namespace std;
int board[104][104];
int brid[104][104];
int N;
int dirR[4] = {0, 1, 0 ,-1};
int dirC[4] = {1, 0, -1, 0};
int flag = 0;

void dfs(int curR, int curC){
	board[curR][curC] = flag;
	for (int d = 0; d < 4; d++)
	{
		int nr = curR + dirR[d], nc = curC + dirC[d];
		if(nr <0 || nr>=N || nc<0 || nc>=N) continue;
		if(board[nr][nc] == flag || board[nr][nc] == 0) continue;
		// board[nr][nc] = flag;
		dfs(nr,nc);
	}
	
}
int bfs(int flag){
	memset(brid, 0, sizeof(brid));
	queue<pair<int,int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(board[i][j]==flag){
				q.push({i,j});
			}
		}	
	}
	while(!q.empty()){
	
		int curR = q.front().first, curC = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nr = curR + dirR[d], nc = curC + dirC[d];
			if(nr <0 || nr>=N || nc<0 || nc>=N) continue;
			if(board[nr][nc] == flag || brid[nr][nc]>0) continue;
			if(board[nr][nc] != 0) {
				return brid[curR][curC];
			}
			brid[nr][nc] = brid[curR][curC] +1;
			q.push({nr, nc});
		}
		
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin>>board[i][j];
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if(board[i][j]==1){
				--flag;
				dfs(i, j);
			}

	int ret = 200;

	while(flag<0)
		ret = min(ret, bfs(flag++));

	
	cout<<ret;
}