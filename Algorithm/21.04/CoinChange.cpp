// greedy or dp
// greedy 로 풀 경우 항상 가장 큰 돈부터 시작해서 최대로 사용하고 다음으로 이동
// 근데 이렇게 하면 [7, 3], 9 가 들어왔을 때 처리를 못함
// 왜 처리를 못하는가? 하면 가장 큰 수를 가장 우선 사용하는 게 최선이 아닐 수 있기 때문임
// dp 로 풀어야 하는듯
// dp[i] : i 원 만드는데 필요한 최소 갯수
// dp[i] = min(dp[i], dp[i-coins[N]]+1) 이런 느낌
// 범위 정하는 데 살짝 헷갈리게 했음
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[100002];
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        fill(dp, dp+100002, 10002);
        int cnt=0, su = 0;
        for(int k: coins){
            if(k < 10002)
                dp[k] = 1;
        }
        
        for(int i=1; i<=amount; i++){
            if(dp[i] != 10002){
                for(int k : coins){
                    if(k < 10002)
                        dp[i+k] = min(dp[i+k],dp[i]+1);
                    // int idx = i - k + 1;
                    // if(idx>=1)
                    //     dp[i] = min(dp[i], dp[idx]+1);
                }
            }
            
        }
        if(dp[amount]!=10002)
            return dp[amount];
        return -1;
    }
};