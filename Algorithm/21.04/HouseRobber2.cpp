// dp, 첫 항과 끝 항이 연결되어 있음
// max(dp[n], dp[n-1]) 이렇게 하면 될려나?
// 아니면 첫항을 포함하는 경우, 포함 안 하는 경우 2개로 나누나?
// 세가지 경우임 첫항 포함 마지막 포함X, 첫항 포함X 마지막 포함, 첫항 포함X 마지막 포함X
// 두가지 경우로 나눌 수 있는듯.. 1. 두번째 항부터 끝까지 2. 첫항부터 끝-1 까지
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> dp(101, 0);
        vector<int> dp2(101, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        }
        
        return max(dp[nums.size()-2], dp2[nums.size()-1]);
    }
};