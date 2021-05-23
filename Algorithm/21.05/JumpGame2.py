# dp[i] : i번째까지 가는 최소 점프
# for i in range(n):
#  dp[i+nums[i]] = min(dp[i] + 1, dp[i+nums[i]]) 이런 느낌
class Solution:
    def jump(self, nums: List[int]) -> int:
        dp = [0] * len(nums)
        for i in range(len(nums)): # 0, 1, 2, 3, 4
            for j in range(1,nums[i]+1):
                if i+j >= len(nums):
                    continue
                if dp[i+j] == 0:
                    dp[i+j] = dp[i] + 1
                else:
                    dp[i+j] = min(dp[i+j], dp[i]+1)
        return dp[len(nums)-1]

# bfs
class Solution:
    def jump(self, nums: List[int]) -> int:
        n, l, r, level = len(nums), 0, 0, 0
        
        while r < n-1:
            level += 1
            maxend = r + 1
            for i in range(l, r+1):
                if i + nums[i] >= n -1:
                    return level
                maxend = max(maxend, i+nums[i])
            l, r = r+1, maxend
        return level