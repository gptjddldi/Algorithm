// BOJ 2263. 트리의 순회

#include <bits/stdc++.h>
using namespace std;
int N, k;
vector<int> pre, post, in;

void recursion(int in_st, int in_end, int post_st, int post_end) {
	if (in_st > in_end || post_st > post_end) return;
	int root = post[post_end];
	cout << root << ' ';
	int left_end = find(in.begin(), in.end(), root) - in.begin();

	recursion(in_st, left_end - 1, post_st, post_st + left_end - 1 - in_st); //left
	recursion(left_end + 1, in_end, post_st + left_end - in_st, post_end - 1); //right
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin>>k;
		in.push_back(k);
	}
	for (int i = 0; i < N; i++)
	{
		cin>>k;
		post.push_back(k);
	}
	recursion(0, N-1, 0, N-1);
	
}