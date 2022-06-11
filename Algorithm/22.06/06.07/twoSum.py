class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        h = {}
        for idx, n in enumerate(nums):
            if n in h:
                return [h[n], idx]
            h[target-n] = idx
