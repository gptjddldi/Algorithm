// BOJ 1107. 리모컨

#include <bits/stdc++.h>
using namespace std;
int tar, N, cnt, diff = 499999;
int cur[2], lo;
vector<int> v;
bool impos[10];
int k=0;

int getTenth(int t) {
	int n = 1;
	while(t >= 10){
		t /= 10;
		n++;
	}
	return n;
}

void getMinDiff(int i) {
	if (i / 10 > tar) {
		return;
	}
	for (int a = 0; a < 10; a++)
	{
		if (!impos[a]) {
			cur[0] += i * a;
			if (diff > abs(tar - cur[0])) {
				diff = abs(tar - cur[0]);
				cur[1] = cur[0];
			}
			else if (diff == abs(tar - cur[0])) {
				if(abs(getTenth(cur[0])) < abs(getTenth(cur[1]))) cur[1] = cur[0];
			}
			getMinDiff(i * 10);
			cur[0] -= i * a;
		}
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> tar;
	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		impos[a] = true;
	}
	getMinDiff(1);
	if (diff + getTenth(cur[1]) > abs(100 - tar)) {
		cout << abs(100 - tar);
	}else cout <<diff + getTenth(cur[1]);
}