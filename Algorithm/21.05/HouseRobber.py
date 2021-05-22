# dp[i] : i번째 집을 털었을 때 버는 돈
class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        if len(nums) <= 2:
            return max(nums)
        else:
            dp[2] = nums[0] + nums[2]
        dp[0] = nums[0]
        dp[1] = nums[1]
        
        for i in range(3,len(nums)):
            dp[i] = max(dp[i-2], dp[i-3]) + nums[i]
            
        return max(dp[len(nums)-1], dp[len(nums)-2])