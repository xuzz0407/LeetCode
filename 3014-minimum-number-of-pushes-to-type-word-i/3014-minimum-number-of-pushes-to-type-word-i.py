class Solution:
    def minimumPushes(self, word: str) -> int:
        k, rem = divmod(len(word), 8)
        return (4 * k + rem) * (k + 1)