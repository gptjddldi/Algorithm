// BOJ 2589 보물섬

#include <bits/stdc++.h>
using namespace std;

int N,M;
int dirC[4] = {1, 0, -1, 0};
int dirR[4] = {0, 1, 0, -1};
string treasure[52];
int dis[52][52];
int bfs(int r, int c){
	memset(dis, 0, sizeof(dis));
	queue<pair<int, int>> q;
	q.push({r, c});
	int ret=0;
	dis[r][c] = 1;
	while(!q.empty()){
		int curR = q.front().first, curC = q.front().second;
		q.pop();
		ret = max(ret, dis[curR][curC]);
		for (int d = 0; d < 4; d++)
		{
			int nr = curR + dirR[d], nc = curC + dirC[d];
			if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
			if(dis[nr][nc] || treasure[nr][nc]=='W') continue;
			dis[nr][nc] = dis[curR][curC] + 1;
			q.push({nr,nc});
		}
	}
	return ret-1;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M;
	for (int i = 0; i < N; i++)
	{
		cin>>treasure[i];
	}
	int mexi = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(treasure[i][j] == 'W') continue;
			mexi = max(mexi, bfs(i,j));
		}
	}
	
	cout<<mexi;
}