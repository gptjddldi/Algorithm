// BOJ 11279. 최대 힙
#include <bits/stdc++.h>
using namespace std;
int N;
int heap[100002];
int sz = 0;

void add(int x){
    sz++;
    heap[sz] = x;
    int idx = sz;
    while(idx!=1){
        int par = idx/2;
        if(heap[par]>heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() {
    if (sz==0) return 0;
    return heap[1];
}

void pop() {
    if(sz==0) return;
    swap(heap[1], heap[sz]);
    sz--;
    int idx = 1;
    while(idx*2 <= sz){
        int min_child;
        if(heap[idx*2] > heap[idx*2+1] || idx*2+1>sz) min_child=idx*2;
        else min_child = idx*2+1;
        if(heap[idx] > heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }

}


int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    int k;
    while(N--){
        cin>>k;
        if(k==0) {
            cout<<top()<<'\n';
            pop();
        }
        else add(k);
    }
}