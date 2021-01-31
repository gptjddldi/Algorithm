// BOJ 1967. 트리의 지름

/*
	Root Node 에서 dfs => target(시작점)
	target 에서 dfs => 끝점
*/
#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> graph[10001]; // graph[a] = {i, j} a 노드와 i 노드 사이의 간선 : j

bool vis[10000];
int N;
int p, c, d; //parent, child, distance
int res;
int target;
void dfs(int start, int dis) {
	for (int i = 0; i < graph[start].size(); i++)
	{
		int nxt = graph[start][i].first;
		int D = graph[start][i].second;
		if(vis[nxt]) continue;
		vis[nxt] = true;
		if(dis + D > res){
			target = nxt;
			res = dis + D;
		}
		dfs(nxt, dis + D);
	}
	
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for (int i = 1; i < N; i++)
	{
		cin >> p >> c >> d;
		graph[p].push_back({c, d});
		graph[c].push_back({p, d});
	}
	vis[1] = true;
	dfs(1, 0);

	memset(vis, false, sizeof(vis));
	vis[target] = true;
	dfs(target, 0);
	cout<<res;
}