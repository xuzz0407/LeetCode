class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @cache  
        def dfs(i: int, j: int) -> int:
            if i < j:
                return 0
            if j < 0:
                return 1
            res = dfs(i - 1, j)   
            if s[i] == t[j]:
                res += dfs(i - 1, j - 1)  
            return res
        return dfs(len(s) - 1, len(t) - 1)
