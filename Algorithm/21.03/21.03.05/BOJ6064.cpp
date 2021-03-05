// BOJ 6064. 카잉 달력
// dp[i][j] : <i:j> 일 때 년도 
// if(i<M && j<N) dp[i+1][j+1] = dp[i][j] + 1, dp[40000][40000] 은 너무 용량이 크다 (X)

// X 를 고정시켜서 찾기 예를들면 10 12 3 9 가 주어지면,
// x=3 이 나올 수 있는 경우는 3, 13, 23, ...
// 각각의 경우의 모듈러 연산이 y 인 값을 찾으면 됨

#include <bits/stdc++.h>
using namespace std;
int t, M, N, x, y;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        int day = -1;
        cin>>M>>N>>x>>y;
        for (int i = x; i <= M*N; i+=M)
        {
            if (i % N == (y==N ? 0 : y)){
                day = i;
                break;
            }
        }
        cout<<day<<'\n';
    }
}