// BOJ 11660. 구간 합 구하기 5
// 어려워쓰
#include <bits/stdc++.h>
using namespace std;
int N,M, s;
int board[1025][1025];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			int a;
			cin>>a;
			board[i][j] = board[i][j-1] + a + board[i-1][j] - board[i-1][j-1];
		}

	for (int i = 0; i < M; i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<board[x2][y2] - board[x1-1][y2] - board[x2][y1-1] + board[x1-1][y1-1]<<'\n';
	}
	
}