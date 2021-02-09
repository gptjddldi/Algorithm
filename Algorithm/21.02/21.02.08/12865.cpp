// BOJ 12865. 평범한 배낭
/*
    dp[i][j] :  i번째 물건까지 확인했음, 현재 무게 j
    1. i+1 번째를 담는 경우
        dp[i+1][j+w[i+1]] = max(dp[i][j] + val[i+1], dp[i+1][j+w[i+1]])
    2. i+1 번째를 담지 않는 경우
        dp[i+1][j] = max(dp[i][j], dp[i+1][j])
    
    *max_element(dp[N], dp[N]+K)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[102][100002];
vector<pair<int,int>> bag;
int N, K;
// dp[i][j] :  i번째 물건까지 확인했음, 현재 무게 j
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>K;
    int w, v;
    for (int i = 0; i < N; i++){
        cin>>w>>v;
        bag.push_back({w,v}); //{무게, 값}
    }
    dp[1][bag[1].first] = bag[1].second;
    for (int i = 1; i <= N; i++)
    {
        int wei = bag[i-1].first, val = bag[i-1].second;
        for (int j = 0; j <= K; j++)
        {
            if(j<wei) {
                dp[i][j] = dp[i-1][j];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-wei]+val);
        }
    }
    cout<<dp[N][K];
}