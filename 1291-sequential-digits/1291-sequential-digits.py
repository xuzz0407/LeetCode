class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []
        for d in range(1, 10):
            x = d
            for i in range(d, 10):
                if x > high: break
                if x >= low: ans.append(x)
                x = x * 10 + i + 1
        ans.sort()
        return ans