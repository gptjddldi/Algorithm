// BOJ 1085. 직사각형에서 탈출

#include <bits/stdc++.h>
using namespace std;
int x, y, w, h;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>x>>y>>w>>h;
	int disX = min(w-x, x);
	int disY = min(h-y, y);
	cout<<min(disX, disY);
}