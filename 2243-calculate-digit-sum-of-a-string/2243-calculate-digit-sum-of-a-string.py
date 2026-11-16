class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            tmp = []
            for i in range(0, len(s), k):
                total = sum(map(int, s[i:i+k]))
                tmp.append(str(total))
            s = ''.join(tmp)
        return s