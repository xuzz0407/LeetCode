class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def check(s):
            l = 0
            for ch in s:
                if ch == '(':
                    l += 1
                if ch == ')':
                    if l == 0: return False
                    l -= 1

            return l == 0

        level = {s}

        while True:
            ans = [t for t in level if check(t)]
            if ans: return ans
            nxt = set()

            for t in level:
                for i, ch in enumerate(t):
                    if ch in '()':
                        nxt.add(t[:i]+t[i+1:])

            level = nxt


            

