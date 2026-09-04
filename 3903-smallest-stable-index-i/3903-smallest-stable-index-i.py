class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        res = [0] * n
        min_num = float('inf')
        max_num = float('-inf')
        left = 0
        right = n - 1

        for i in range(n):
            max_num = max(max_num, nums[left + i])
            min_num = min(min_num, nums[right - i])
            res[left + i] += max_num
            res[right - i] -= min_num

        for i, num in enumerate(res):
            if num <= k:
                return i

        return -1
