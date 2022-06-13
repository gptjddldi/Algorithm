# O(n^2), dp
class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        dp = [[0]*l for _ in range(l)]
        for i in range(l):
            dp[i][i] = 1
        ret = s[0]
        for j in range(l):
            for i in range(j):
                if s[i] == s[j] and (dp[i+1][j-1] or j == i+1):
                    dp[i][j] = 1
                    ret = max(ret, s[i:j+1], key=len)
        return ret


class Solution:
    def longestPalindrome(self, s: str) -> str:
        l = len(s)
        dp = [[0]*l for _ in range(l)]
        for idx, val in enumerate(s):
            dp[idx][idx] = 1
        ret = ''
        for i in range(l):
            ret = max(self.helper(i, i, s), self.helper(
                i, i+1, s), ret, key=len)
        return ret

    def helper(self, i, j, s):
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
        return s[i+1:j]
