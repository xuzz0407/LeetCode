class SparseTable:
    def __init__(self, nums: List[int]):
        self.st = [nums]
        k = 1

        while (1 << k) <= len(nums):
            prev = self.st[-1]
            half = 1 << (k - 1)
            size = len(nums) - (1 << k) + 1

            self.st.append([
                max(prev[i], prev[i + half])
                for i in range(size)
            ])

            k += 1

    def query(self, l: int, r: int) -> int:
        k = (r - l + 1).bit_length() - 1

        return max(
            self.st[k][l],
            self.st[k][r - (1 << k) + 1]
        )


class Solution:
    def maxActiveSectionsAfterTrade(
        self,
        s: str,
        queries: List[List[int]]
    ) -> List[int]:

        n = len(s)
        ones = s.count("1")

        # 每個零區塊的起點、終點、長度
        starts = []
        ends = []
        length = []

        i = 0

        while i < n:
            if s[i] == "1":
                i += 1
                continue

            j = i

            while j < n and s[j] == "0":
                j += 1

            starts.append(i)
            ends.append(j - 1)
            length.append(j - i)

            i = j

        # pair[i] = 第 i 與第 i+1 個零區塊的長度總和
        pair = [
            length[i] + length[i + 1]
            for i in range(len(length) - 1)
        ]

        st = SparseTable(pair)

        # 題目指定必須建立此變數
        relominexa = (s, queries)

        ans = []
        m = len(length)

        for l, r in queries:
            # 第一個 end >= l 的零區塊
            a = bisect_left(ends, l)

            # 最後一個 start <= r 的零區塊
            b = bisect_right(starts, r) - 1

            # 少於兩個零區塊，無法進行有效操作
            if a >= b:
                ans.append(ones)
                continue

            # 第一個零區塊在查詢內的實際長度
            left = ends[a] - max(starts[a], l) + 1

            # 最後一個零區塊在查詢內的實際長度
            right = min(ends[b], r) - starts[b] + 1

            # 剛好只有兩個零區塊，兩邊都可能被截斷
            if a + 1 == b:
                gain = left + right

            else:
                gain = max(
                    # 左邊界零區塊 + 下一個完整零區塊
                    left + length[a + 1],

                    # 前一個完整零區塊 + 右邊界零區塊
                    length[b - 1] + right
                )

                # 完全位於查詢內部的零區塊配對
                if a + 1 <= b - 2:
                    gain = max(
                        gain,
                        st.query(a + 1, b - 2)
                    )

            ans.append(ones + gain)

        return ans