// BOJ 1676. 팩토리얼 0의 개수
// 5, 25, 125 가 들어갈 때마다 1개씩 오름
#include<bits/stdc++.h>
using namespace std;
int N,ret,d=5;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    while(N){
        N /= d;
        ret +=N;
    }
    cout<<ret;
}