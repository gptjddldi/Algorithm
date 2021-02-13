// BOJ 11286. 절댓값 힙
#include <bits/stdc++.h>
using namespace std;
int N;

struct absol {
    bool operator()(const int& x, const int& y) const{
        if(abs(x)==abs(y)) return x>y;
         return abs(x) > abs(y); 
        
    }
};

priority_queue<int, vector<int>, absol> PQ;


int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    int k;
    while(N--){
        cin>>k;
        if(k==0) {
            if(PQ.empty()) cout<<'0'<<'\n';
            else{
                cout<<PQ.top()<<'\n';
                PQ.pop();
            }
        }
        else PQ.push(k);
    }
}