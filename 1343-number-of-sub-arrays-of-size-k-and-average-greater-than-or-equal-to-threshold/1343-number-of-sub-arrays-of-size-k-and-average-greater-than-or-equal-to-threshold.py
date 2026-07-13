class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        ans = s = 0

        for i, x in enumerate(arr):
            s += x
            if i < k - 1: continue
            if s >= k * threshold:
                ans += 1
            s -= arr[i-k+1]
        
        return ans