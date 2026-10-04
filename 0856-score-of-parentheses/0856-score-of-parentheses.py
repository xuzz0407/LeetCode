class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans, depth = 0, 0
        for i, ch in enumerate(s):
            depth += 1 if ch == '(' else -1
            if ch == ')' and s[i-1] == '(':
                ans += 1 << depth
        return ans