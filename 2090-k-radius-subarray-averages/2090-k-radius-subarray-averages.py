class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        avg = [-1] * len(nums)
        s = 0 # sum

        for i, x in enumerate(nums):
            s += x

            if i < k * 2: continue

            avg[i-k] = s // (k*2+1)
            s -= nums[i-k*2]
        
        return avg