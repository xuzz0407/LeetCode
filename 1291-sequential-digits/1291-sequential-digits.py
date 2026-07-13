class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        
        for s in range(1, 10):
            n = 0
            for dig in range(s, 10):
                n = n * 10 + dig
                if low <= n <= high: ans.append(n)
                if n > high: break
        
        return sorted(ans)