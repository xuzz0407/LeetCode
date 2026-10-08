class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        l, res, cnt = 0, 0, 0

        while cnt < n:
            if s[cnt] == '(':
                l += 1
                cnt += 1
                continue

            if l > 0: l -= 1
            else: res += 1

            if cnt < n-1 and s[cnt+1] == ')':
                cnt += 2
            else:
                res += 1
                cnt += 1

        return res + l * 2
        