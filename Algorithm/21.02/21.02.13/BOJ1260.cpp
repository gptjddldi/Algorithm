// BOJ 1260. 대칭 차집합

#include <bits/stdc++.h>
using namespace std;
int N1, N2;
set<int> A,B;
int n,m; // A-B, B-A
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N1>>N2;
    n=N1, m=N2;
    for (int i = 0; i < N1; i++)
    {
        int k;
        cin>>k;
        A.insert(k);
    }
    for (int i = 0; i < N2; i++)
    {
        int k;
        cin>>k;
        B.insert(k);
        if(A.find(k) != A.end()){ // 집합 A 에 B 의 원소가 있다면.
            n--;
        }
    }
    for(int k: A){
        if(B.find(k) != B.end()){ // 집합 B 에 A의 원소가 있다면.
            m--;
        }
    }
    
    cout<<n+m;
    
}