// BOJ 11053. 가장 긴 증가하는 부분 수열

#include<bits/stdc++.h>
using namespace std;

int A[1004];
int D[1004];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	D[0] = 1;
	for (int i = 1; i < N; i++)
	{
		D[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j]) {
				D[i] = max(D[i], D[j] + 1);
			}
		}
	}
	cout << *max_element(D, D + N);
}