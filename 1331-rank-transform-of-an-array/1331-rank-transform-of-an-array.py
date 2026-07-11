class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rk = {x: i for i, x in enumerate(sorted(set(arr)), 1)}
        return [rk[x] for x in arr]