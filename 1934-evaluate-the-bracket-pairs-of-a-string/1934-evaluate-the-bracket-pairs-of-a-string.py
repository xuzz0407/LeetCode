class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        # 每个 knowledge[i] 都是一个键值对，插入字典
        # 查字典时，如果 key 不在字典中，那么 value 为 '?'
        d = defaultdict(lambda: '?', knowledge)

        ans = []
        left = -1
        for i, ch in enumerate(s):
            if ch == '(':
                left = i  # 记录左括号的位置
            elif ch == ')':
                # 替换左右括号之间的子串
                t = s[left + 1: i]
                ans.append(d[t])
                left = -1
            elif left < 0:  # ch 不在左右括号之间
                ans.append(ch)
        return ''.join(ans)

