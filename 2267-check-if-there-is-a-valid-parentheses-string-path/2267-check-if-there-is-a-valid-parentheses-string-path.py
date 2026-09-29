class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])

        if (m + n) % 2 == 0 or grid[0][0] == ')' or grid[-1][-1] == '(':
            return False

        @cache
        def dfs(x: int, y: int, c: int)-> bool:
            if c > m - x + n - y - 1:
                return False
            
            if x == m - 1 and y ==  n - 1:
                return c == 1

            c += 1 if grid[x][y] == '(' else -1

            if c < 0: 
                return False

            return x < m - 1 and dfs(x+1, y, c) or  y < n - 1 and dfs(x, y+1, c)
            
        return dfs(0, 0, 0)