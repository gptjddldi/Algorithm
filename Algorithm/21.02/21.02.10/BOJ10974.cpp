// BOJ 10974. 모든 순열

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> arr;

void nextPer(vector<int>& arr){
    for(int c: arr) cout<<c<<' ';
    cout<<'\n';
    int m = N-1;
    while(m>0 && arr[m] < arr[m-1]) m--; // 가장 긴 증가하지 않는 배열의 최대 인덱스 찾기
    if(m<=0) return;
    int j = N-1;
    while(arr[j] <= arr[m-1]) j--;
    iter_swap(arr.begin() + j, arr.begin() + m - 1);
    reverse(arr.begin() + m, arr.end());

    nextPer(arr);
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        arr.push_back(i);
    }
    nextPer(arr);
}