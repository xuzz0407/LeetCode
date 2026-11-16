class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            tmp = []
            for i in range(0, len(s), k):
                tmp.append(str(sum(map(int, s[i:i+k]))))
            s = ''.join(tmp)
        return s