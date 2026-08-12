class SegmentTree:
    def __init__(self, s):
        self.s = list(s)
        self.n = len(s)

        self.pre = [0] * (4 * self.n)
        self.suf = [0] * (4 * self.n)
        self.mx = [0] * (4 * self.n)

        self.build(1, 0, self.n - 1)

    def pull(self, o, l, r):
        if l == r:
            self.pre[o] = self.suf[o] = self.mx[o] = 1
            return

        mid = (l + r) // 2
        left = o * 2
        right = left + 1

        self.pre[o] = self.pre[left]
        self.suf[o] = self.suf[right]
        self.mx[o] = max(self.mx[left], self.mx[right])

        # 左右區間邊界字元相同
        if self.s[mid] == self.s[mid + 1]:
            self.mx[o] = max(self.mx[o], self.suf[left] + self.pre[right])

            # 整個左區間都是相同字元
            if self.pre[left] == mid - l + 1:
                self.pre[o] += self.pre[right]

            # 整個右區間都是相同字元
            if self.suf[right] == r - mid:
                self.suf[o] += self.suf[left]

    def build(self, o, l, r):
        if l == r:
            self.pre[o] = self.suf[o] = self.mx[o] = 1
            return

        mid = (l + r) // 2

        self.build(o * 2, l, mid)
        self.build(o * 2 + 1, mid + 1, r)

        self.pull(o, l, r)

    def update(self, o, l, r, idx):
        if l == r:
            return

        mid = (l + r) // 2

        if idx <= mid:
            self.update(o * 2, l, mid, idx)
        else:
            self.update(o * 2 + 1, mid + 1, r, idx)

        self.pull(o, l, r)

    def change(self, idx, c):
        self.s[idx] = c
        self.update(1, 0, self.n - 1, idx)

    def query(self):
        return self.mx[1]


class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: list[int]) -> list[int]:

        seg = SegmentTree(s)
        ans = []

        for idx, c in zip(queryIndices, queryCharacters):
            seg.change(idx, c)
            ans.append(seg.query())

        return ans