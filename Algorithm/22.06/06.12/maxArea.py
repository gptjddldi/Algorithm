class Solution:
    def maxArea(self, h: List[int]) -> int:
        ret = 0
        st, ed = 0, len(h)-1
        while st < ed:
            ret = max(ret, (ed-st)*min(h[st], h[ed]))
            if h[st] <= h[ed]:
                st += 1
            else:
                ed -= 1
        return ret
