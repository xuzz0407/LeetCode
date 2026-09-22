# 线段树有两个下标，一个是线段树节点的下标，另一个是线段树维护的区间的下标
# 节点的下标：从 1 开始，如果你想改成从 0 开始，需要把左右儿子下标分别改成 node*2+1 和 node*2+2
# 区间的下标：从 0 开始
class SegmentTree:
    def __init__(self, a: List[int], k: int):
        self._n = n = len(a)
        self._k = k
        self._tree = [None] * (2 << (n - 1).bit_length())
        self._build(a, 1, 0, n - 1)

    # 合并信息
    def _merge_data(self, a: Tuple[int, List[int]], b: Tuple[int, List[int]]) -> Tuple[int, List[int]]:
        cnt = a[1].copy()
        left_mul = a[0]
        for rx, c in enumerate(b[1]):
            cnt[left_mul * rx % self._k] += c
        return left_mul * b[0] % self._k, cnt

    def _new_data(self, val: int) -> Tuple[int, List[int]]:
        mul = val % self._k
        cnt = [0] * self._k
        cnt[mul] = 1
        return mul, cnt

    # 合并左右儿子的信息到当前节点
    def _maintain(self, node: int) -> None:
        self._tree[node] = self._merge_data(self._tree[node * 2], self._tree[node * 2 + 1])

    # 用 a 初始化线段树
    # 时间复杂度 O(n)
    def _build(self, a: List[int], node: int, l: int, r: int) -> None:
        if l == r:  # 叶子
            self._tree[node] = self._new_data(a[l])  # 初始化叶节点的值
            return
        m = (l + r) // 2
        self._build(a, node * 2, l, m)  # 初始化左子树
        self._build(a, node * 2 + 1, m + 1, r)  # 初始化右子树
        self._maintain(node)

    def _update(self, node: int, l: int, r: int, i: int, val: int) -> None:
        if l == r:  # 叶子（到达目标）
            self._tree[node] = self._new_data(val)
            return
        m = (l + r) // 2
        if i <= m:  # i 在左子树
            self._update(node * 2, l, m, i, val)
        else:  # i 在右子树
            self._update(node * 2 + 1, m + 1, r, i, val)
        self._maintain(node)

    def _query(self, node: int, l: int, r: int, ql: int, qr: int) -> Tuple[int, List[int]]:
        if ql <= l and r <= qr:  # 当前子树完全在 [ql, qr] 内
            return self._tree[node]
        m = (l + r) // 2
        if qr <= m:  # [ql, qr] 在左子树
            return self._query(node * 2, l, m, ql, qr)
        if ql > m:  # [ql, qr] 在右子树
            return self._query(node * 2 + 1, m + 1, r, ql, qr)
        l_res = self._query(node * 2, l, m, ql, qr)
        r_res = self._query(node * 2 + 1, m + 1, r, ql, qr)
        return self._merge_data(l_res, r_res)

    # 更新 a[i] 为 _new_data(val)
    # 时间复杂度 O(log n)
    def update(self, i: int, val: int) -> None:
        self._update(1, 0, self._n - 1, i, val)

    # 返回用 _merge_data 合并所有 a[i] 的计算结果，其中 i 在闭区间 [ql, qr] 中
    # 时间复杂度 O(log n)
    def query(self, ql: int, qr: int) -> Tuple[int, List[int]]:
        return self._query(1, 0, self._n - 1, ql, qr)

class Solution:
    def resultArray(self, nums: List[int], k: int, queries: List[List[int]]) -> List[int]:
        t = SegmentTree(nums, k)
        n = len(nums)
        ans = []
        for index, value, start, x in queries:
            t.update(index, value)
            _, cnt = t.query(start, n - 1)
            ans.append(cnt[x])
        return ans

