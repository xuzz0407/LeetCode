class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n, m = len(word1), len(word2)

        last = [-1] * m

        # 從右往左匹配 word2
        i, j = n - 1, m - 1
        while i >= 0 and j >= 0:
            if word1[i] == word2[j]:
                last[j] = i
                j -= 1
            i -= 1

        ans = []
        j = 0
        can_skip = True

        for i in range(n):
            if j == m:
                break

            # 正常匹配
            if word1[i] == word2[j]:
                ans.append(i)
                j += 1

            # 使用唯一一次 mismatch
            elif can_skip and (j == m - 1 or i < last[j + 1]):
                ans.append(i)
                j += 1
                can_skip = False

        return ans if j == m else []