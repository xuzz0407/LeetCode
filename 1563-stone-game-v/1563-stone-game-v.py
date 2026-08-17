class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)

        pre = [0] * (n + 1)
        for i, x in enumerate(stoneValue):
            pre[i + 1] = pre[i] + x

        def get_sum(l, r):
            return pre[r + 1] - pre[l]

        dp = [[0] * n for _ in range(n)]

        leftMax = [[0] * n for _ in range(n)]
        rightMax = [[0] * n for _ in range(n)]

        for l in range(n - 1, -1, -1):
            leftMax[l][l] = stoneValue[l]
            rightMax[l][l] = stoneValue[l]

            k = l - 1

            for r in range(l + 1, n):
                total = get_sum(l, r)
 
                while (k + 1 < r and 2 * get_sum(l, k + 1) <= total):
                    k += 1

                ans = 0

                # left <= right
                if k >= l:
                    ans = max( ans, leftMax[l][k])

                # left >= right
                if (k >= l and 2 * get_sum(l, k) == total):
                    start = k + 1

                else:
                    start = k + 2

                if start <= r:
                    ans = max(ans, rightMax[start][r])

                dp[l][r] = ans

                leftMax[l][r] = max(leftMax[l][r - 1], total + dp[l][r])

                rightMax[l][r] = max(rightMax[l + 1][r], total + dp[l][r])

        return dp[0][n - 1]