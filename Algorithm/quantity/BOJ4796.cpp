// BOJ 4796. 캠핑

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int L,P,V, cnt=0;
    while (true)
    {
        cnt++;
        cin>>L>>P>>V;
        if(!L && !P && !V) break;
        int a = V / P;
        int b = V % P;
        int ret = b >= L ? a*L + L : a*L + b;
        cout<<"Case "<<cnt<<": "<<ret<<'\n';
    }
    
}