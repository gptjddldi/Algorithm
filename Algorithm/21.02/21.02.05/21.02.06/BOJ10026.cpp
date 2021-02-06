// BOJ 10026. 적록색약

#include <bits/stdc++.h>
using namespace std;
int N;
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};
string board1[102];
char board2[102][102];
int cnt1, cnt2;
bool vis1[102][102], vis2[102][102];

void dfs1(int curR, int curC){
	// vis[curR][curC] = true;
	for (int d = 0; d < 4; d++)
	{
		int nr = curR + dirR[d];
		int nc = curC + dirC[d];
		if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
		if(vis1[nr][nc] || board1[nr][nc] != board1[curR][curC]) continue;
		vis1[nr][nc] = true;
		dfs1(nr,nc);
	}
	
}

void dfs2(int curR, int curC){
	// vis[curR][curC] = true;
	for (int d = 0; d < 4; d++)
	{
		int nr = curR + dirR[d];
		int nc = curC + dirC[d];
		if(nr<0 || nr>=N || nc<0 || nc>=N || vis2[nr][nc]) continue;
		if(vis2[nr][nc] || board2[nr][nc] != board2[curR][curC]) continue;
		vis2[nr][nc] = true;
		dfs2(nr,nc);
	}
	
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for (int i = 0; i < N; i++)
	{
		cin>>board1[i];
		for (int j = 0; j < N; j++)
		{
			if(board1[i][j]!='B') board2[i][j] = 'R';
			else board2[i][j] = 'B';
		}
		
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(vis1[i][j] == 0){
				dfs1(i,j);
				cnt1++;
			}
			if(vis2[i][j]==0){
				dfs2(i,j);
				cnt2++;
			}
		}
		
	}
	cout<<cnt1<<' '<<cnt2;
	
}