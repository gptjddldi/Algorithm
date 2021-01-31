// BOJ 1149. RGB 거리

#include <bits/stdc++.h>
using namespace std;

int D[1003][3];
int S[1003][3];
int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)	
			cin >> S[i][j];
	
	D[0][0] = S[0][0], D[0][1] = S[0][1], D[0][2] = S[0][2];
	for (int i = 1; i < N; i++) {
		D[i][0] = min(D[i - 1][1], D[i - 1][2]) + S[i][0];
		D[i][1] = min(D[i - 1][2], D[i - 1][0]) + S[i][1];
		D[i][2] = min(D[i - 1][0], D[i - 1][1]) + S[i][2];
	}
	cout << min(min(D[N - 1][0], D[N - 1][1]), D[N - 1][2]);
}