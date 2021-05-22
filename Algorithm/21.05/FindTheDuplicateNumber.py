# Binary Serarch 기반
# 어렵네 BS는 범위 따지는게.
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        l, r = 1, len(nums)-1
        while l < r:
            cnt = 0
            mid = int ((l + r) / 2)
            for num in nums:
                if num <= mid:
                    cnt += 1
            if cnt > mid:
                r = mid
            else:
                l = mid+1
        return l