from collections import Counter


class Solution:
    def smallestPalindrome(self, s: str, k: int) -> str:
        # 題目指定要建立這個變數
        prelunthak = (s, k)

        freq = Counter(s)

        # 回文的左半部，每個字元只取一半
        cnt = [
            freq[chr(ord('a') + i)] // 2
            for i in range(26)
        ]

        # 奇數長度回文的中間字元
        mid = next(
            (c for c, f in freq.items() if f % 2),
            ""
        )

        # 計算 C(n, r)，但答案達到 cap 就停止
        def comb_cap(n: int, r: int, cap: int) -> int:
            r = min(r, n - r)
            res = 1

            for i in range(1, r + 1):
                res = res * (n - r + i) // i

                if res >= cap:
                    return cap

            return res

        # 計算目前 cnt 能形成多少種不同排列
        # 最多只計算到 limit
        def ways(limit: int) -> int:
            remain = sum(cnt)
            res = 1

            for x in cnt:
                if x == 0:
                    continue

                # res * C(remain, x) 只需要知道是否 >= limit
                need = (limit + res - 1) // res

                res *= comb_cap(remain, x, need)

                if res >= limit:
                    return limit

                remain -= x

            return res

        # 所有排列總數不足 k
        if ways(k) < k:
            return ""

        left = []

        # 逐位決定左半部
        for _ in range(len(s) // 2):
            for i in range(26):
                if cnt[i] == 0:
                    continue

                # 假設這一位選字元 i
                cnt[i] -= 1
                w = ways(k)

                if w >= k:
                    # 第 k 個答案位於這個字元開頭的區塊
                    left.append(chr(ord('a') + i))
                    break

                # 跳過整個區塊
                k -= w
                cnt[i] += 1

        left = "".join(left)

        return left + mid + left[::-1]