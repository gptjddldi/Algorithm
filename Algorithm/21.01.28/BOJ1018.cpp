// BOJ 1018. 체스판 다시 칠하기

#include <bits/stdc++.h>
using namespace std;
int N, M;
string board[51];

string white[8] = {
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"}
};

string black[8] = {
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
	{"BWBWBWBW"},
	{"WBWBWBWB"},
};

int count(int row, int col, string arr[]){
	int cnt=0;
	for (int i = row; i < row+8; i++)
		for (int j = col; j < col+8; j++)
		{
			if(board[i][j] != arr[i-row][j-col]){
				// cout<<i<<','<<j<<endl;
				cnt++;
			}
		}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	int res = 64;
	for (int i = 0; i < N; i++) cin>>board[i];
	for (int i = 0; i < N-7; i++)
	{
		for (int j = 0; j < M-7; j++)
		{
			res = min(res,min(count(i,j,white), count(i,j,black)));
		}
		
	}
	cout<<res;
}