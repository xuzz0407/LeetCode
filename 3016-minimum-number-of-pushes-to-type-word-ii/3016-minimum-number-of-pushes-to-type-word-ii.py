class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = sorted(Counter(word).values(), reverse=True)

        return sum(freq * (i // 8 + 1) for i, freq in enumerate(cnt))