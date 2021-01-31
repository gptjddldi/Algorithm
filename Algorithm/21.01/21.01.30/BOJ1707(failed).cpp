// BOJ 1707. 이분 그래프

/*
	임의의 정점 v에 대해서 v와 거리가 1인 정점들 서로의 거리가 1이 아닐 때
	=> bfs
*/

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
int N;
string res[5];
int V, E, a, b;
int flag = 1;
vector<int> graph[200000];
int check[200000];

 string bfs(int k) {
 	queue<int> q;
	q.push(k);
	check[k] = flag;
	while (!q.empty()) {
		flag *= -1;
		int cur = q.front();
		q.pop();
		for (int nxt : graph[cur]) {
			if (check[nxt] == -1*flag) {
				cout<<"nxt: "<<nxt <<", cur: "<<cur;
				return "NO";
			}
			q.push(nxt);
			check[nxt] = flag;
		}
	}
	return "YES";
 }

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int j = 0; j < N; j++) {
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= V; i++)
		{	
			cout<<"i: "<<i<<endl;
			res[j] = bfs(i);
			if (res[j] == "NO") break;
		}
		memset(graph, 0, V);

	}
	for (string s : res) if(s!="")cout << s;

}












/*
vector<int> ve;
			for (int nxt : graph[i]) ve.push_back(nxt);
			for (int a : ve) {
				for (int b : graph[a])
					if (find(ve.begin(), ve.end(), b) == ve.end()) continue;
					else {
						res[j] = "NO";
					}
			}
			*/