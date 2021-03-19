// BOJ 1927. 최소 힙
#include <bits/stdc++.h>
using namespace std;
/* 직접 구현
int heap[100002];
int sz;
void add(int x){
    sz++;
    heap[sz] = x;
    int idx = sz;
    while(idx!=1){
        int par = idx/2;
        if(heap[par]<heap[idx])break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}
void pop(){
    if(sz==0) {
        cout<<0<<'\n';
        return;
    }
    cout<<heap[1]<<'\n';
    swap(heap[1], heap[sz--]);
    int idx = 1;
    while(idx*2 <=sz){
        int min_child;
        if(heap[idx*2]<heap[idx*2+1] || idx*2+1>sz) min_child=idx*2;
        else min_child=idx*2+1;
        if(heap[idx] < heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}
*/
// pq 사용
priority_queue<int, vector<int>, greater<>> pq;

void pop(){
    if(pq.empty()) cout<<"0\n";
    else {
        cout<<pq.top()<<'\n';
        pq.pop();
    }
}
int t;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int num;
        cin>>num;
        if(!num) pop();
        else pq.push(num);
    }
}