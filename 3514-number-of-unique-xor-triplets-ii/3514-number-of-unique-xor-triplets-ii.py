class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        nums = list(set(nums))
        # x ^ y ^ z = (x ^ y) ^ z
        xy = {x ^ y for x in nums for y in nums}
        ans = {k ^ z for k in xy for z in nums}
        return len(ans)