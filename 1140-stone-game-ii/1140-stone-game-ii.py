class Solution:
    def stoneGameII(self, s: List[int]) -> int:
        n = len(s)
        for i in range(n - 2, -1, -1):
            s[i] += s[i + 1]  # 后缀和

        @cache  # 缓存装饰器，避免重复计算 dfs（一行代码实现记忆化）
        def dfs(i: int, m: int) -> int:
            if i + m * 2 >= n:  # 全拿
                return s[i]
            return s[i] - min(dfs(i + x, max(m, x)) for x in range(1, m * 2 + 1))

        return dfs(0, 1)

