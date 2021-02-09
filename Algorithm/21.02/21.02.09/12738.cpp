// BOJ 12738. 가장 긴 증가하는 부분수열 3

#include <bits/stdc++.h>
using namespace std;
int N, lisCnt;

// vector<int> arr;
int arr[1000002];
// int lis[1000002];
vector<int>ve;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++){
        // int k;
        // cin>>k;
        // arr.push_back(k);
        cin>>arr[i];
    }
    
    for (int i = 0; i < N; i++){
        if(i==0 || ve.back() < arr[i]){
            ve.push_back(arr[i]);
        } else{
            auto it = lower_bound(ve.begin(), ve.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<ve.size();
}