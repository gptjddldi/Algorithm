// BOJ 1644. 소수의 연속 합

#include <bits/stdc++.h>
using namespace std;
bool vis[4000002];
vector<int> p_list;
int N, cnt;
void getPrime(int num){
	for (int i = 2; i <= num; i++)
	{
		if(vis[i])
			continue;
		p_list.push_back(i);
		for (int j = i*2; j <= num; j+=i)
		{
			vis[j] = true;
		}
		
	}
	
	
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	getPrime(N);
	for (int i = 0; i < p_list.size(); i++)
	{
		int temp = i;
		int sum = 0;
		while(sum<N && temp<p_list.size()){
			sum += p_list[temp++];
			if(sum==N) {
				cnt++;
			}
		}
	}
	cout<<cnt;
}