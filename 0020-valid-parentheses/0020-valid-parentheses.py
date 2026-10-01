class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        if len(s) % 2 == 1: return False

        for ch in s:
            if ch == '(':
                st.append(')')
            elif ch == '[':
                st.append(']')
            elif ch == '{':
                st.append('}')
            elif not st or st.pop() != ch:
                return False
                
        return not st