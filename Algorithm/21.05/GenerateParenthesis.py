
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if not n:
            return []
        l, r, ans = n, n, []
        self.dfs(l,r, ans, "")
        return ans
    
    def dfs(self, l, r, ans, string):
        if l > r:
            return
        if not l and not r:
            ans.append(string)
            return
        if l:
            self.dfs(l-1, r, ans, string+"(")
        if r:
            self.dfs(l, r-1, ans, string+")")