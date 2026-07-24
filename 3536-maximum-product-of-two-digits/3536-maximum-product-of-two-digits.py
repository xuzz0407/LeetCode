class Solution:
    def maxProduct(self, n: int) -> int:
        n = sorted(str(n))
        return int(n[-1]) * int(n[-2])