class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        ans = inf
        n = len(nums)
        for i in range(n - l + 1):
            s = 0
            for j in range(i, min(i + r, n)):
                s += nums[j]
                if s > 0 and j - i + 1 >= l:
                    ans = min(ans, s)
        return -1 if ans == inf else ans