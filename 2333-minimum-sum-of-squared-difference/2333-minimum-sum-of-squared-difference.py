class Solution:
    def minSumSquareDiff(self, nums1: list[int], nums2: list[int], k1: int, k2: int) -> int:
        k = k1 + k2
        diff = [abs(x-y) for x, y in zip(nums1, nums2)]
        if sum(diff) <= k: return 0
        l, r = 0, max(diff)

        while l < r:
            mid = (l + r) // 2
            if sum(max(0, x-mid) for x in diff) <= k:
                r = mid
            else: l = mid + 1

        tmp = sum(max(0, x-l) for x in diff)
        k -= tmp
        ans = sum(min(x, l) ** 2 for x in diff)
        return ans - k * (2 * l - 1)
