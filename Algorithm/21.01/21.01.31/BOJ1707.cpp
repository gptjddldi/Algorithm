// BOJ 1707. 이분 그래프

/*
	임의의 정점 v에 대해서 v와 거리가 1인 정점들 서로의 거리가 1이 아닐 때
	=> bfs
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> res(5);
int V, E, a, b;
// int flag = 1;
string ans;
vector<int> graph[200000];
int check[200000];

void dfs(int start) {
	int flag = check[start];
	for(int k:graph[start]){
		if(check[k] == flag) {
			ans = "NO";
			return;
		}
		else if (check[k]==0){ 
			check[k] = -flag;
			dfs(k);
		}

	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	res.resize(N);
	fill(res.begin(), res.end(), "YES");
	for (int j = 0; j < N; j++) {

		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	memset(check, 0, max(V,E));		
		for (int i = 1; i <= V; i++)
		{
			if(check[i]) continue;
			check[i] = 1;
			ans = "YES";
			dfs(i);	
			if(ans == "NO") res[j] = ans;
		}
	memset(graph, 0, max(V,E));
	}

	for(string s:res) cout<<s<<'\n';
}