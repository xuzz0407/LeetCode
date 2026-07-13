class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        max_s , s= -inf, 0

        for i, x in enumerate(nums):
            s += x
            if i < k - 1: continue
            max_s = max(max_s, s)
            s -= nums[i-k+1]
        
        return max_s / k