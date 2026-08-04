class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        st = set(nums)
        return [i for i in range(min(nums)+1, max(nums)) if i not in st]