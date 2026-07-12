class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        return list(map({x: i for i, x in enumerate(sorted(set(arr)), 1)}.__getitem__, arr))