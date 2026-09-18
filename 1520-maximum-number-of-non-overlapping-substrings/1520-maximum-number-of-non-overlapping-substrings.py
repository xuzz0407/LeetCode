class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        n = len(s)

        first = [n] * 26
        last = [-1] * 26

        for i, ch in enumerate(s):
            x = ord(ch) - ord('a')
            first[x] = min(first[x], i)
            last[x] = i

        ans = []
        right = -1

        for l in range(n):
            x = ord(s[l]) - ord('a')

            # 只從第一次出現的位置開始
            if first[x] != l:
                continue

            r = last[x]
            i = l
            valid = True

            while i <= r:
                y = ord(s[i]) - ord('a')

                # 有字元第一次出現在 l 左邊
                # 代表這個區間不可能合法
                if first[y] < l:
                    valid = False
                    break

                r = max(r, last[y])
                i += 1

            if not valid:
                continue

            # 沒有重疊
            if l > right:
                ans.append(s[l:r + 1])

            # 有重疊，換成更短、結束更早的新區間
            else:
                ans[-1] = s[l:r + 1]

            right = r

        return ans