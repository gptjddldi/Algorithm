// BOJ 1747. 소수&팰린드롬

#include<bits/stdc++.h>
using namespace std;
int N;
bool notPrime[1500000];
bool isPellin(int x){
    string st = to_string(x);
    for (int i = 0; i < st.length()/2; i++)
    {
        if(st[i]!=st[st.length()-i-1]) return false;
    }
    return true;
}
int sol(int x){
    notPrime[1] = true;
    for (int i = 2; i*i <= 1500000; i++)
    {
        if(notPrime[i]) continue;
        for (int j = i*i; j <= 1500000; j+=i)
        {
            notPrime[j] = true;
        }
    }
    while(true){
        if(!notPrime[x]){ //소수일 때
        // cout<<x<<'\n';

            if(isPellin(x)) return x;
        }
        x++;            
    }
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    cout<<sol(N);

    // cout<<notPrime[N];
}