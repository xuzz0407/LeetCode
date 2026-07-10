class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[int]:
        # order[rank] = 排序位置 rank 對應的原節點
        order = sorted(range(n), key=lambda i: nums[i])

        # 排序後的數值
        values = [nums[node] for node in order]

        # pos[node] = 原節點 node 在排序後的位置
        pos = [0] * n
        for rank, node in enumerate(order):
            pos[node] = rank

        # -------------------------------------------------
        # 1. 計算每個位置所屬的連通塊
        # -------------------------------------------------
        component = [0] * n

        for i in range(1, n):
            component[i] = component[i - 1]

            # 相鄰差距超過 maxDiff，代表新的連通塊
            if values[i] - values[i - 1] > maxDiff:
                component[i] += 1

        # -------------------------------------------------
        # 2. 雙指標計算 far[i]
        # far[i] = 從 i 一步可以到達的最右位置
        # -------------------------------------------------
        far = [0] * n
        right = 0

        for left in range(n):
            right = max(right, left)

            while (
                right + 1 < n
                and values[right + 1] - values[left] <= maxDiff
            ):
                right += 1

            far[left] = right

        # -------------------------------------------------
        # 3. 建立倍增表
        # up[k][i] = 從 i 跳 2^k 次後的位置
        # -------------------------------------------------
        LOG = n.bit_length()

        up = [far[:]]

        for k in range(1, LOG):
            previous = up[k - 1]

            current = [
                previous[previous[i]]
                for i in range(n)
            ]

            up.append(current)

        # -------------------------------------------------
        # 4. 處理查詢
        # -------------------------------------------------
        answer = []

        for u, v in queries:
            # 同一個節點，不需要走任何邊
            if u == v:
                answer.append(0)
                continue

            left = pos[u]
            right = pos[v]

            if left > right:
                left, right = right, left

            # 不同連通塊，無法到達
            if component[left] != component[right]:
                answer.append(-1)
                continue

            current = left
            steps = 0

            # 找出「還沒有到達 right」的最多跳躍次數
            for k in range(LOG - 1, -1, -1):
                next_position = up[k][current]

                if next_position < right:
                    current = next_position
                    steps += 1 << k

            # 最後再跳一步即可到達或跨過 right
            answer.append(steps + 1)

        return answer