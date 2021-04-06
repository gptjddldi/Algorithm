// dp 로 푼다면?
// dp[i] : i번까지 사용했을 때 갯수
// dp[i][j] : i 를 j 번 썼을 때 갯수?
// dp[i] : 합이 i 가 되도록 즉 return dp[target];
// dp[1] = 1 dp[2] = 2 dp[3] = 3 dp[4] = 7
// dp[5] = 12
// dp[i] = dp[i-nums[0]] + dp[i-nums[1]] + dp[i-nums[2]] 이런 느낌인가?
class Solution {
    unsigned int dp[1001];
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for(int i=1; i<=target; i++)
            for(int k : nums){
                if(i>=k) dp[i] += dp[i-k];
            }
        return dp[target];
    }
};