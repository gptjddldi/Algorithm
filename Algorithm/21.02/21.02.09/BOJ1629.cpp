// BOJ 1629. 곱셈

#include <bits/stdc++.h>
using namespace std;
long long a, b, c;

long long multi(long long i, long long j){
    if(j==1) return i % c;
    long long val = multi(i, j/2) % c;
    val = val*val % c;
    if(j%2==0) return val % c;
    return (val*i) % c;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>a>>b>>c;
    cout<<multi(a, b);
}