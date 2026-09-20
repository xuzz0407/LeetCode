class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum((ord('{') - ord(ch)) * i for i, ch in enumerate(s, 1))