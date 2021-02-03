// BOJ 2751. 수 정렬하기 2

#include <bits/stdc++.h>
using namespace std;
int arr[1000002];
int tmp[1000002];
int N;
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st, ridx = mid;
	for (int i = st; i < en; i++)
	{
		if (ridx == en) tmp[i] = arr[lidx++];
		else if (lidx == mid) tmp[i] = arr[ridx++];
		else if (arr[ridx] <= arr[lidx]) tmp[i] = arr[ridx++];
		else tmp[i] = arr[lidx++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i];
}
void merge_sort(int st, int en){
	if(st+1 == en) return ;
	int mid = (st + en) / 2;
	merge_sort(st, mid);
	merge_sort(mid, en);
	merge(st, en);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for (int i = 0; i < N; i++)	cin>>arr[i];
	merge_sort(0, N);
	for(int i=0; i<N;i++) cout<<arr[i]<<'\n';
}