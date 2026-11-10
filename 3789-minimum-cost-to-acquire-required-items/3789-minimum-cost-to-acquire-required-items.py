class Solution:
    def minimumCost(self, cost1: int, cost2: int, costBoth: int, need1: int, need2: int) -> int:
        return min(need1, need2) * min(cost1 + cost2, costBoth) + max(need1 - need2, 0) * min(cost1, costBoth) + max(need2 - need1, 0) * min(cost2, costBoth)