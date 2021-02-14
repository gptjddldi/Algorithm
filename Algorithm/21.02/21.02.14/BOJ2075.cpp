// BOJ 2075. N번째 큰 수
// 최소 힙, 내가 만든 힙은 시간초과ㅠ_ㅠ STL 은 통과
#include <bits/stdc++.h>
using namespace std;
int N;
int heap[1501];
priority_queue<int, vector<int>, greater<int>> pq;
int sz;
void add(int x){
    heap[++sz] = x;
    int idx = sz;
    while(idx!=1){
        int par = idx/2;
        if(heap[par]<heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int ret(){
    return heap[1];
}
void pop(){
    if(sz==0) return;
    swap(heap[1], heap[sz--]);
    int idx = 1;
    while(idx*2 <= sz){
        int min_child;
        if(heap[idx*2] < heap[idx*2+1] || idx*2+1>sz) min_child=idx*2;
        else min_child=idx*2+1;
        if(heap[idx] < heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    int k;
    for (int i = 1; i <= N; i++){
        cin>>k;
        pq.push(k);
    }

    for (int i = 0; i < N-1; i++){
        for (int j = 1; j <= N; j++)
        {
            cin>>k;
            pq.push(k);
            pq.pop();
        }

    }
    cout<<pq.top();
}