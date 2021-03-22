// BOJ 1991. 트리 순회
#include <bits/stdc++.h>
using namespace std;
int N;
bool vis[26];
vector<char> t[26];
char root, le, ri;
void pre(char rt, char le, char ri){
    cout<<rt;
    // cout<<le;
    if(le != '.') pre(le, t[le-'A'][0], t[le-'A'][1]);
    if(ri != '.') pre(ri, t[ri-'A'][0], t[ri-'A'][1]);
}
void mid(char rt, char le, char ri){
    if(le != '.') mid(le, t[le-'A'][0], t[le-'A'][1]);
    cout<<rt;
    if(ri != '.') mid(ri, t[ri-'A'][0], t[ri-'A'][1]);
}
void pos(char rt, char le, char ri){
    if(le != '.') pos(le, t[le-'A'][0], t[le-'A'][1]);
    if(ri != '.') pos(ri, t[ri-'A'][0], t[ri-'A'][1]);
    cout<<rt;

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>root>>le>>ri;
        // cout<<">>"<<root<<le<<ri<<'\n';
        t[root-'A'].push_back(le);
        t[root-'A'].push_back(ri);
    }
    // cout<<t[0][0]<<t[0][1];
    pre('A', t[0][0], t[0][1]);   
    cout<<'\n';
    mid('A', t[0][0], t[0][1]);
    cout<<'\n';
    pos('A', t[0][0], t[0][1]);
}