// BOJ 11279. 최대 힙
#include <bits/stdc++.h>
using namespace std;
int N;
priority_queue<int> pq; //최대힙
// priority_queue<int, vector<int> greater<int>> PQ; // 최소힙

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    int k;
    while(N--){
        cin>>k;
        if(k==0) {
            if(pq.empty()) cout<<'0'<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else pq.push(k);
    }
}