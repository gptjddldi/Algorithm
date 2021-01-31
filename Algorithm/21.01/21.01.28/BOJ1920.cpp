// BOJ 1920. 수 찾기
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<long long int> v;

// int binarySearch(int target, int len){
// 	int st = 0;
// 	int end = v.size();
// 	while(true) {
// 	int mid = (st+end) / 2;
// 	if(target > v[mid]) st = mid+1; 
// 	else if(target<v[mid]) end = mid-1;
// 	else return 1;
// 	if (end<st) return 0;
// 	}
// }

int binarySearch(int st, int end, int val){
	if(end>=st) {
		int mid = (st+end) / 2;
		if(v[mid] == val) return 1;
		else if(v[mid] > val) return binarySearch(st, mid-1, val);
		else if (v[mid] < val) return binarySearch(mid+1, end, val);
	}
	return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>N;
	vector<int>res;
	int k;
	while(N--){
	cin>>k;
	v.push_back(k);
	}
	sort(v.begin(), v.end());
	cin >> M;
	while(M--){
		cin>>k;
		res.push_back(binarySearch(0, v.size(), k));
	}
	for(int c:res) cout<<c<<'\n';
}