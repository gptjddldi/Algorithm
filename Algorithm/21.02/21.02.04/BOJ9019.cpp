// BOJ 9019. DSLR

#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> v;
bool vis[10000];
string bfs(int cur, string s){ //current index
	queue<pair<int, string>> q;
	q.push({cur, s});
	vis[cur] = true;

	while(!q.empty()){
		auto c = q.front();
		q.pop();

		if(c.first==v[cur].second) return c.second;
		if(!vis[toleft(c.first)]) {
			vis[toleft(c.first)] = true;
			q.push({toleft(c.first), s+"L"});
		}
		if(!vis[toRight(c.first)]) {
			vis[toRight(c.first)] = true;
			q.push({toRight(c.first), s+"R"});
		}
		if(!vis[(c.first * 2) % 10000]) {
			vis[(c.first * 2) % 10000] = true;
			q.push({(c.first * 2) % 10000, s+"D"});
		}
		if(!vis[Sub(c.first)]) {
			vis[Sub(c.first)] = true;
			q.push({Sub(c.first), s+"S"});
		}

	}
}

int toleft(int i) {
	return (i % 1000) * 10 + i / 1000;
}
int toRight(int i) {
	return (i%10) * 1000 + i/10;
}
int Sub(int i) {
	if (i == 0) return 9999;
	else return i - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	int first, second;
	for (int i = 0; i < N; i++)
	{
		cin>>first>>second;
		v.push_back({first, second});
	}
	for (int i = 0; i < N; i++)
	{
		cout<<bfs(i,"");
	}
	
	// cout << toRight(1234);
}