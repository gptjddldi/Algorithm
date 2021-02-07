// BOJ 1016. 제곱 ㄴㄴ수

#include <bits/stdc++.h>
using namespace std;
// bool arr1[5001];
bool notPrime[1300001];
// int p_list[1000000];
vector<long long int> p_list;
bool arr[1000002];
vector<long long int> v;
unsigned long long int mini, maxi;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	//	long long int N = 1000000000000; // 1조
	cin >> mini >> maxi;

	// for (long long int i = 2; i <= 1000001; i++)
	// {
	// 	v.push_back(i * i);
	// }
	// cout<<v.front();


	for (int i = 2; i <= 1000000; i++)
	{
		if (notPrime[i]) continue;
		p_list.push_back(i);
		for (int j = i * 2; j <= 1000000; j += i)
		{
			notPrime[j] = true;
		}
	}

	int cnt = maxi - mini + 1;
	for (auto i : p_list) {
		unsigned long long int k = i * i; // k : 소수의 제곱

		for (unsigned long long int j = mini%k == 0 ? mini : mini + k - (mini % k); j <= maxi; j += k)
			// j는 N이상의, k를 약수로 하는 N과 가장 가까운 수
		{
			int idx = j - mini;

			if (arr[idx] == true) continue;
			arr[idx] = true;
//			cout << j << ',';
			cnt--;
		}
	}
//	if (maxi == mini) cnt=0;

	// int cnt = 0;
	// for (long long int i = mini; i <= maxi; i++)
	// {
	// 	if (arr[i - mini] == true) continue;
	// 	cout << i << ',';
	// 	cnt++;
	// }
	cout << cnt;

	// int a = 5000;
	// for (int i = 2; i * i <= a; i++)
	// {
	// 	if (arr1[i]) continue;
	// 	for (int j = i; j <= a; j += i)
	// 	{
	// 		arr1[j] = true;
	// 	}
	// }


	// for (int i = 1; i <= a; i++)
	// {
	// 	if (arr1[i] == false) cout << i << ',';
	// }

}
// 1000000000000 // 1조
// 1000001000000 // 1조 1백만