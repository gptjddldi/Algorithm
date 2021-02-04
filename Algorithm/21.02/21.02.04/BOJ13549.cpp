// BOJ 13549. 숨바꼭질3
#include <bits/stdc++.h>
using namespace std;
int N, K, t;
int dis[100002];
int bfs() {
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) {
			return dis[K];
		}
		if (cur + 1 < 100002 && dis[cur + 1] > dis[cur] + 1) {
			dis[cur + 1] = dis[cur] + 1;
			q.push(cur + 1);
		}
		if (cur -1 >= 0 && dis[cur - 1] > dis[cur] + 1) {
			dis[cur - 1] = dis[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 < 100002 && dis[cur *2] > dis[cur] ) {
			dis[cur * 2] = dis[cur];
			q.push(cur * 2);
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill(dis, dis + 100002, 999999);
	cin >> N >> K;
	dis[N] = 0;
//	bfs();
	cout << bfs();
}