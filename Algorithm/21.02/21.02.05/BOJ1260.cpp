// BOJ 1260. DFS와 BFS
#include<bits/stdc++.h>
using namespace std;

int N,M,V;
vector<int> graph[1002];
bool vis[1002];
bool comp(int a, int b){
	if(a>=b) return true;
	else return false;
}
void bfs(int st){
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while(!q.empty()){
		int cur = q.front();
		cout<<cur<<' ';
		q.pop();
		for(int c: graph[cur]){
			if(vis[c]) continue;
			q.push(c);
			vis[c] = true;
		}
	}
}

// void dfs(int st){
// 	stack<int> s;
// 	s.push(st);
// 	vis[st] = true;
// 	while(!s.empty()){
// 		int cur = s.top();
// 		cout<<cur<<' ';
// 		s.pop();
// 		for(int c: graph[cur]){
// 			if(vis[c]) continue;
// 			s.push(c);
// 			vis[c] = true;
// 		}
// 	}
// }

void dfs(int st){
	cout<<st<<' ';
	for(int c: graph[st]){
		if(vis[c]) continue;
		vis[c] = true;
		dfs(c);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M>>V;
	int v1, v2;
	for (int i = 0; i < M; i++){
		cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 0; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	// for(int c: graph[1]) cout<<c;
	vis[V] = true;
	dfs(V);
	cout<<'\n'; 
	memset(vis, 0, N+1);
	bfs(V);
}