class Solution:
    def countCommas(self, n: int) -> int:
        ans, c = 0, 1000
        while c <= n:
            ans += n - c + 1
            c *= 1000
        
        return ans