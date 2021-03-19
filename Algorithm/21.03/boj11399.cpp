// BOJ 11399. ATM
// GREED
#include<bits/stdc++.h>
using namespace std;
int N, ret;
int arr[1004];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
        cin>>arr[i];
    sort(arr, arr+N); // O(nlogn)
    for (int i = 0; i < N; i++)
    {
        ret += (N-i) * arr[i];
    }
    cout<<ret;
}