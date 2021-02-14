// BOJ 2014. 소수의 곱
#include <bits/stdc++.h>
using namespace std;

long long arr[100], mv;
map<long long, bool> vis; 
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int K,N; cin>>K>>N;
    for (int i = 0; i < K; i++)
    {
        cin>>arr[i];
        pq.push(arr[i]);
        vis[arr[i]] = true;
        mv = max(mv, arr[i]);
    }
    int cnt = 0;
    while(cnt<N-1){
        long long tp = pq.top();
        for (int i = 0; i < K; i++)
        {
            long long val = arr[i] * tp;
            if(pq.size()>=N && val>=mv) continue;

            if(!vis[val]) {
                pq.push(val);
                vis[val] = true;
                mv = max(mv, val);
            }
        }
        pq.pop();
        cnt++;
    }
    cout<<pq.top();
}