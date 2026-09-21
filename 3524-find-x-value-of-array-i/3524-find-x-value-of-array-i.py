class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for n in nums:
            n %= k
            ndp = [0] * k
            ndp[n] += 1

            for r in range(k):
                ndp[(r * n) % k] += dp[r]
            
            for r in range(k):
                ans[r] += ndp[r]

            dp = ndp

        return ans