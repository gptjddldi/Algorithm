//BOJ 2610. 회의 준비
// 위원회 : 그래프 탐색하면서 찾음
// 각각의 위원회에 대해 플로이드 적용 
// -> 각 행에 대한 최댓값이 제일 작은 행의 번호 출력
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
int N, M, gn;
vector<int> ve[200];
vector<int> gr[200];
bool vis[200];
int dis[200][200];
vector<int> ret;
void dfs(int st) {
	vis[st] = true;
	gr[gn].push_back(st);
	for (int nxt : ve[st]) {
		if (!vis[nxt]) dfs(nxt);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	fill(&dis[0][0], &dis[150][150], MAX);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
		dis[a][b] = 1, dis[b][a] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		dis[i + 1][i + 1] = 0;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}

		}

	}
	
	for (int i = 1; i <= N; i++)
	{
		if (!vis[i]) {
			dfs(i);
			gn++;
		}
	}
	cout << gn << '\n';
	
	for (int p = 0; p < gn; p++)
	{

		int s, num, ma = 1000;
		for (auto i : gr[p]) {
			s = 0;
			for (auto j : gr[p]) {
				s = max(s, dis[i][j]);
			}
			if (s < ma) {
				num = i;
				ma = s;
			}
		}
		ret.push_back(num);
	}
	sort(ret.begin(), ret.end());
	for (auto c : ret) cout << c << '\n';
}
