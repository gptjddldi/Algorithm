// dp[i] : i번째 집을 털었을 때 번 돈
// dp[i] = max(dp[i-3], dp[i-2]) + nums[i]
class Solution {
    int dp[101];
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = nums[1];
        if(sz>=3)
            dp[2] = nums[0] + nums[2];
        for(int i=3; i<sz; i++){
            dp[i] = max(dp[i-3], dp[i-2]) + nums[i];
        }
        return max(dp[sz-2],dp[sz-1]);
    }
};