class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        # f[i] 表示从 s[:i] 中选出的回文子串的最大数目
        f = [0] * (n + 1)
        for i in range(k, n + 1):
            f[i] = f[i - 1]  # 不考虑 s[i-1]
            if s[i - k: i] == s[i - k: i][::-1]:
                f[i] = max(f[i], f[i - k] + 1)
            if i > k and s[i - k - 1: i] == s[i - k - 1: i][::-1]:
                f[i] = max(f[i], f[i - k - 1] + 1)
        return f[n]

