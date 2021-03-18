// BOJ 1110. 더하기 사이클

#include<bits/stdc++.h>
using namespace std;
int num, nextNum, a, b, cnt;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>num;
    nextNum = num;
    do{
        a = nextNum%10;
        b = (nextNum/10 + a) % 10;
        nextNum = a*10 + b;
        cnt++;
        // cout<<nextNum<<'\n';
    }while(num!=nextNum);

    cout<<cnt;
}