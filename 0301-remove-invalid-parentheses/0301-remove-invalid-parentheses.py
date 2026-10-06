class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        l = r = 0

        for ch in s:
            if ch == '(':  l += 1
            elif ch == ')':
                if l: l -= 1
                else: r += 1

        ans = set()

        def dfs(i, p, tmp, l, r):
            if tmp < 0: return

            if i == len(s):
                if tmp == 0 and l == 0 and r == 0: ans.add(p)
                return

            ch = s[i]

            if ch == '(': 
                if l: dfs(i+1, p, tmp, l-1, r)
                dfs(i+1, p+ch, tmp+1, l, r)

            elif ch == ')':
                if r: dfs(i+1, p, tmp, l, r-1)
                if tmp: dfs(i+1, p+ch, tmp-1, l, r)

            else: dfs(i + 1, p+ch, tmp, l, r)

        dfs(0, "", 0, l, r)

        return list(ans)