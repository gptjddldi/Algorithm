// dp[i] : i칸까지 올라오는 방법의 수
// dp[i] = dp[i-1] + dp[i-2]
class Solution {
    int dp[46];
public:
    int climbStairs(int n) {
        // dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++)
            dp[i] = dp[i-2]+dp[i-1];
        return dp[n];
    }
};
