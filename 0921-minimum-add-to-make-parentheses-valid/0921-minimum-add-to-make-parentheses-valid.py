class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        l, ans = 0, 0
        for ch in s:
            if ch == '(':
                l += 1
            elif l > 0:
                l -= 1
            else:
                ans += 1

        return ans + l