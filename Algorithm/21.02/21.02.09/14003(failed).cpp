// BOJ 14003. 가장 긴 증가하는 부분수열 5

#include <bits/stdc++.h>
using namespace std;
int N, lisCnt;

// vector<int> arr;
// int arr[1000002];
// int lis[1000002];
vector<double>ve = {-INFINITY, };
unordered_map<double,double> m; // m[cur] = last
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    double k;
    for (int i = 0; i < N; i++){
        cin>>k;
        if(i==0 || ve.back() < k){
            m[k] = ve.back();
            ve.push_back(k);
        } else{ // 이분탐색하여 k 를 ve 의 적당한 자리에 두겠다.
            auto it = lower_bound(ve.begin(), ve.end(), k);
            // cout<<*it;
            m[k] = *it;
            *it = k;
        }
    }
    // cout<<ve.size()<<'\n';
    cout<<m[ve.back()];
}