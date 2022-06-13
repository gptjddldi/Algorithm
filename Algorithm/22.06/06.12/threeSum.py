# Timeout
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = len(nums)
        ret = []
        if l <= 2:
            return []
        for idx, num in enumerate(nums):
            ret = self.twoSum(nums, idx, -num, ret)
            # if fret and fret not in ret:
        return ret

    def twoSum(self, nums, i, target, ret):
        d = {}
        for idx, num in enumerate(nums):
            if i == idx:
                continue
            tmp = sorted([num,  target-num, -target])
            if num in d and tmp not in ret:
                ret.append(tmp)
            d[target-num] = idx
        return ret


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n, p, z = [], [], []
        ret = set()
        for num in nums:
            if num < 0:
                n.append(num)
            elif num > 0:
                p.append(num)
            else:
                z.append(num)

        N, P = set(n), set(p)
        if z:
            for num in P:
                if -num in N:
                    ret.add((-num, 0, num))
        if len(z) >= 3:
            ret.add((0, 0, 0))

        for i in range(len(n)):
            for j in range(i+1, len(n)):
                target = -1*(n[i]+n[j])
                if target in P:
                    ret.add(tuple(sorted([n[i], n[j], target])))

        for i in range(len(p)):
            for j in range(i+1, len(p)):
                target = -1*(p[i]+p[j])
                if target in N:
                    ret.add(tuple(sorted([p[i], p[j], target])))

        return ret
