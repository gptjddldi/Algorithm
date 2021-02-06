// BOJ 1389. 케빈 베이커의 6단계 법칙

#include <bits/stdc++.h>
using namespace std;
int V,E;
vector<int> graph[104]; //은장 백사
int vis[104];
int K, P;
int bfs(int st) {
	memset(vis, 0, sizeof(vis));
    queue<int> q;
	int ret = 0;
    q.push(st);
	vis[st] = 1;
	// vis[st] = 1;
    while(!q.empty()){
        int cur = q.front();
		ret += vis[cur]-1;
        q.pop();
        for(int nxt: graph[cur]){
            if(vis[nxt]) continue;
            vis[nxt] = vis[cur]+1;
            q.push(nxt);
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>V>>E;
    int v1, v2;
    for (int i = 0; i < E; i++)
    {
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }	
    K = bfs(1), P = 1;
    for (int i = 2; i <= V; i++)
    {

		int a = bfs(i);
		if(a==0) continue;
		if(K > a){
			K = a;
			P = i;
		}
    }
    cout<<P;
    
}