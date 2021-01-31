// BOJ 2644. 촌수 계산
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int wei[100];
int dis[100];
bool vis[100];
int cnt = 0, res;
int v, e;
int N, M;
int a, b, a1, b1;

int bfs(int st){
	queue<int> q;
	q.push(st);
	// dis[st] = cnt;
	vis[st] = true;
	while(!q.empty()){
		// cnt++;
		int cur = q.front();
		q.pop();
		if(cur == b) return dis[b];
		for(int nxt: graph[cur]){
			if(vis[nxt]) continue;
			dis[nxt] = dis[cur]+1;
			vis[nxt] = true;
			q.push(nxt);
			// cout<<nxt<<": "<<dis[nxt]<<endl;
		}
	}
	return -1;
	// if(wei[a] && wei[b]) res = abs(wei[a]-wei[b]);
	// fill(wei, wei+100, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>a>>b>>M;
	while(M--){
		cin>>v>>e;
		graph[v].push_back(e);
		graph[e].push_back(v);

	}
	// for (int i = 1; i <= N; i++)
	// {
	// 	if(vis[i]) continue;
	// 	dfs(i);
	// 	if(res) {
	// 		cout<< res;
	// 		return 0;
	// 		}
	// }
	cout<<bfs(a);
	
}