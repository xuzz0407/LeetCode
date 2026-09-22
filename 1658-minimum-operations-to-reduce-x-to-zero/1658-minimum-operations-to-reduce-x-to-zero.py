class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x
        if target < 0: return -1
        s = l = 0
        res = -1

        for r, num in enumerate(nums):
            s += num
            while s > target:
                s -= nums[l]
                l += 1

            if s == target:
                res = max(res, r-l+1)

        return -1 if res < 0 else len(nums) - res