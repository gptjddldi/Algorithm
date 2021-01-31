// BOJ 7562. 나이트의 이동
#include<bits/stdc++.h>
using namespace std;

int N, L;
int r, c;
int r1, c1;
int dir[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
int vis[300][300];
int bfs(){
	queue<pair<int,int>> q;
	q.push({r,c});
	while(!q.empty()){
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nxtR = curR + dir[i][0];
			int nxtC = curC + dir[i][1];
			if(vis[nxtR][nxtC] || nxtR < 0 || nxtR >= L || nxtC < 0 || nxtC >= L) continue;
			vis[nxtR][nxtC] = vis[curR][curC] +1;
			q.push({nxtR, nxtC});
		}
		if(vis[r1][c1]) return vis[r1][c1];
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	while(N--){
		cin>>L;
		memset(vis, 0, sizeof(vis));
		cin>>r>>c>>r1>>c1;
		if(r==r1 && c==c1) cout<<0<<'\n';
		else cout<< bfs()<<'\n';
	}
}