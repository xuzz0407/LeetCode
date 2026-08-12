class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = left = 0
        freq = defaultdict(int)

        for right, x in enumerate(nums):
            freq[x] += 1
            while freq[x] > k:
                freq[nums[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)

        return ans