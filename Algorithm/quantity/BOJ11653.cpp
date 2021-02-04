// BOJ 11653. 소인수분해

#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> v;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
    cin>>N;
    int cnt = 2;
    while(N > 1){
        if(N%cnt==0){
            N /= cnt;
            v.push_back(cnt);
        }
        else cnt++;
    }
    for(int c: v) cout<<c<<'\n';
}