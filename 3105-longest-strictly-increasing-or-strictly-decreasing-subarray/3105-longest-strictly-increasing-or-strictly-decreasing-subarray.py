class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = 1
        inc = dec = 1
        for x, y in pairwise(nums):
            if x < y: inc += 1
            else: inc = 1
            if x > y: dec += 1
            else: dec = 1
            ans = max(ans, inc, dec)
        return ans