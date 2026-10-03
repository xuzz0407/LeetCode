class Solution:
    def longestValidParentheses(self, s: str) -> int:
        st = [-1]  # 未配对括号的下标，其中栈底元素表示永远无法配对的括号下标
        ans = 0

        for i, ch in enumerate(s):
            if ch == '(':
                st.append(i)  # 保存左括号的下标
            elif len(st) > 1:
                st.pop()  # 右括号与栈顶的左括号配对
                ans = max(ans, i - st[-1])  # 从 st[-1]+1 到 i 都已配对，长为 i - st[-1]
            else:  # s[i] 是永远无法配对的右括号
                st[0] = i  # 替换栈底

        return ans
