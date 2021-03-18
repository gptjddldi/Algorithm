// BOJ 1748. 수 이어 쓰기 1

#include <bits/stdc++.h>
using namespace std;
int N, ret;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    int fN = N;
    int cnt = 0;
    while(N){
        if (N > 9){
            ret += 9 * pow(10,cnt) * (cnt+1);
        } else ret += (fN-pow(10,cnt)+1)*(cnt+1);
        N /= 10;
        cnt ++;
    }
    cout<<ret;
}