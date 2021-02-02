// BOJ 1744. 수 묶기
/*
0 < a < b < c < d 일 때 두 수를 묶은 합
1. ab + cd 2. ac + bd 3. ad + bc
1>2 증명
ab + cd > ac + bd
ab - bd > ac - cd
b(a-d) > c(a-d)
(a-d <0 이므로)
b < c (성립)
1>3 증명
ab + cd > ad + bc
ab - ad > bc - cd
(b-d < 0)
a<c (성립)
따라서 항상 가장 큰 두 수를 묶는 게 최댓값임 
=> greedy
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pos, nag;
int N, res;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	int k;
	for (int i = 0; i < N; i++)	{
		cin>>k;
		if (k <= 0) nag.push_back(k);
		else pos.push_back(k);
	}
	sort(nag.begin(), nag.end());
	sort(pos.begin(), pos.end());

	for (int i = (int)pos.size()-1; i > 0; )
	{
		if(pos[i] + pos[i-1] < pos[i] * pos[i-1]){
			res += pos[i] * pos[i-1];
		}
		else res += pos[i] + pos[i-1];
		i-=2;
	}
	if(pos.size()%2==1) res += pos[0];

	for (int i = 0; i+1 < nag.size(); )
	{
		if(nag[i] + nag[i-1] < nag[i] * nag[i-1]){
			res += nag[i] * nag[i+1];
		}
		else res += nag[i] + nag[i-1];
		i+=2;
		// cout<<res;
	}
	if(nag.size()%2==1) res += nag[(int)nag.size()-1];
	cout << res;
}