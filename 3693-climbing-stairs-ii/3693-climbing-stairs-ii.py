class Solution:
    def climbStairs(self, _, costs: List[int]) -> int:
        f0 = f1 = f2 = 0
        for c in costs:
            f0, f1, f2 = f1, f2, min(f0 + 9, f1 + 4, f2 + 1) + c
        return f2