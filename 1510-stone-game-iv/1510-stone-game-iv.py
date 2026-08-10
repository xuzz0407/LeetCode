@cache
def dfs(x: int) -> bool:
    if not x: return False
    i = 1
    while i * i <= x:
        if not dfs(x - i * i):
            return True
        i += 1
    return False

class Solution:
    def winnerSquareGame(self, n: int) -> bool:  
        return dfs(n)