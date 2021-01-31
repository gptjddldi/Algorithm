//BOJ 11725. 트리의 부모 찾기

/*
	트리에서 임의의 정점에 대해 bfs를 돌릴 때, 이미 방문한 노드는 부모 노드이고,
	방문하지 않은 노드는 자식노드임
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> tree[100002];
int vis[100002];
vector<int> parent(100002);
int N;

void bfs() {
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int nxt: tree[cur]){
			if(vis[nxt]) {
				parent[cur] = nxt;
				continue;
			}
			vis[nxt] = true;
			q.push(nxt);
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	for (int i = 0; i < N-1; i++)
	{
		int v, e;
		cin>>v>>e;
		tree[v].push_back(e);
		tree[e].push_back(v);
	}
	bfs();
	for (int i = 2; i <= N; i++)
	{
		cout<<parent[i]<<'\n';
	}
	
}