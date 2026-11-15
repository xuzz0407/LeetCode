class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        odd = s = 0
        for x in arr:
            s += x
            odd += s % 2
        return odd * (len(arr) + 1 - odd) % 1_000_000_007