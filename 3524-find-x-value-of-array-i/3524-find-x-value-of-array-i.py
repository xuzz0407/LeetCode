class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for x in nums:
            f = [0] * k
            x %= k
            f[x] = 1

            for i, cnt in enumerate(dp):
                f[i * x % k] += cnt

            for i in range(k):
                ans[i] += f[i]

            dp = f
            
        return ans