class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        ones = s.count("1")
        pre = None
        gain = 0
        i = 0

        while i < len(s):
            if s[i] == "1":
                i += 1
                continue

            j = i
            while j < len(s) and s[j] == "0":
                j += 1

            cur = j - i

            if pre is not None:
                gain = max(gain, pre + cur)

            pre = cur
            i = j

        return ones + gain