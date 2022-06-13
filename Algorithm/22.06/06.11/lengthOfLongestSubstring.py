# O(N)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        h = {}
        ret = 0
        st = 0
        for idx, val in enumerate(s):
            if val in h:
                st = max(st, h[val] + 1)
            h[val] = idx
            ret = max(ret, idx-st+1)
        return ret

# O(N)


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # h = {}
        lis = [0 for _ in range(130)]
        ret = 0
        st = 0
        for idx, val in enumerate(s):
            i = ord(val)
            if lis[i] and lis[i] >= st:
                st = lis[i]
            else:
                ret = max(ret, idx - st + 1)
            lis[i] = idx + 1

        return ret
