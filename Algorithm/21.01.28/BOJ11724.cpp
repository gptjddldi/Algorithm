// BOJ 11724. 연결 요소의 개수
#include <bits/stdc++.h>
using namespace std;

int node, edge, cnt;
vector<int> graph[1004];
bool vis[1004];
void dfs(int cur){
	for(int nxt: graph[cur]){
		if(vis[nxt]) continue;
		vis[nxt] = true;
		dfs(nxt);
	}
	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>node>>edge;
	int a,b;
	for (int i = 0; i < edge; i++)
	{
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= node; i++)
	{
		if(vis[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << cnt;
}