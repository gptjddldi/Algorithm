class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        ret = 20002

        for idx, num in enumerate(nums):
            tar = target - num
            l, r = idx+1, len(nums)-1
            while l < r and l != idx and r != idx:
                s = nums[l] + nums[r]
                ret = min(ret, s+num, key=lambda x: abs(target-x))
                # print(nums[l], nums[r], num)
                if s < tar:
                    l += 1
                    if l == idx:
                        l += 1
                else:
                    r -= 1
                    if r == idx:
                        r -= 1
        return ret
