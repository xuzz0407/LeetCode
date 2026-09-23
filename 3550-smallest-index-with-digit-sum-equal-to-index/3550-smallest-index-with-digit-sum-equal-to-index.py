class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        return next((i for i, x in enumerate(nums) if sum(map(int, str(x))) == i), -1)