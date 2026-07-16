class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        pre = [0] * n
        res = 0

        for i, x in enumerate(nums):
            res = max(res, x)
            pre[i] = gcd(x, res)
        
        pre.sort()
        return sum(gcd(pre[i], pre[-1-i]) for i in range(n // 2))