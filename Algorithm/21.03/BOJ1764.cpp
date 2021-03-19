// BOJ 1764. 듣보잡

#include<bits/stdc++.h>
using namespace std;
int N,M;
set<string>s1;
set<string>s2;
vector<string> ve;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    string st;
    for (int i = 0; i < N; i++)
    {
        cin>>st;
        s1.insert(st);
    }

    for (int i = 0; i < M; i++)
    {
        cin>>st;
        if(s1.find(st)==s1.end()) continue;
        else s2.insert(st);
    }
    cout<<s2.size()<<'\n';
    for(auto a: s2) cout<<a<<'\n';
}