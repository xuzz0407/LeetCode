class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        # digits[d] = d 對 2、3、5、7 的質因數貢獻
        factors = [
            (0, 0, 0, 0),  # 0，不會使用
            (0, 0, 0, 0),  # 1
            (1, 0, 0, 0),  # 2
            (0, 1, 0, 0),  # 3
            (2, 0, 0, 0),  # 4
            (0, 0, 1, 0),  # 5
            (1, 1, 0, 0),  # 6
            (0, 0, 0, 1),  # 7
            (3, 0, 0, 0),  # 8
            (0, 2, 0, 0),  # 9
        ]

        # 將 t 分解成 2、3、5、7 的指數
        need = []

        for p in (2, 3, 5, 7):
            count = 0

            while t % p == 0:
                t //= p
                count += 1

            need.append(count)

        # t 還有其他質因數，無法由數位 1~9 組成
        if t > 1:
            return "-1"

        # 將剩餘質因數需求轉成：
        # 最少數量、且排列後最小的數位字串
        def build(required: list[int]) -> str:
            required = required[:]
            result = []

            # 優先使用能壓縮較多質因數的數位
            for digit in range(9, 1, -1):
                contribution = factors[digit]

                while all(required[j] >= contribution[j] for j in range(4)):
                    result.append(str(digit))

                    for j in range(4):
                        required[j] -= contribution[j]

            # result 是由大到小收集，反轉後最小
            return "".join(reversed(result))

        n = len(num)

        total = [0, 0, 0, 0]
        first_zero = n

        # 計算 num 所有非零數位的質因數貢獻
        for i, ch in enumerate(num):
            digit = int(ch)

            if digit == 0:
                first_zero = min(first_zero, i)
            else:
                for j in range(4):
                    total[j] += factors[digit][j]

        # num 本身已經符合
        if (first_zero == n and all(total[j] >= need[j] for j in range(4))):
            return num

        # 若存在 0，只有第一個 0 及其左邊的位置能作為修改點。
        # 因為第一個不同位置右邊可以任意重建，
        # 但保留的前綴不能包含 0。
        start = first_zero if first_zero < n else n - 1

        # have 表示 num[:start] 的質因數貢獻
        have = [0, 0, 0, 0]

        for ch in num[:start]:
            digit = int(ch)

            for j in range(4):
                have[j] += factors[digit][j]

        # 從右往左決定第一個增加的位置
        for i in range(start, -1, -1):
            current = int(num[i])
            suffix_length = n - i - 1

            # 新數位必須比原數位大，而且不能是 0
            for digit in range(max(1, current + 1), 10):
                remaining = [max(0, need[j] - have[j] - factors[digit][j]) for j in range(4)]

                suffix = build(remaining)

                if len(suffix) <= suffix_length:
                    ones = "1" * (suffix_length - len(suffix))

                    return (num[:i] + str(digit) + ones + suffix)

            # 下一輪考慮位置 i - 1
            # 因此 num[i - 1] 不再屬於保留前綴
            if i > 0:
                previous_digit = int(num[i - 1])

                for j in range(4):
                    have[j] -= factors[previous_digit][j]

        # 同長度找不到，就建立更長的數字
        suffix = build(need)

        # 長度至少比 num 多 1，也必須放得下所有必要數位
        answer_length = max(n + 1, len(suffix))

        return "1" * (answer_length - len(suffix)) + suffix