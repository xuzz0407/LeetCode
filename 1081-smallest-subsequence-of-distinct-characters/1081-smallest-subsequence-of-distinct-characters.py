class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = {c: i for i, c in enumerate(s)}
        st = []
        inst = set()

        for i, c in enumerate(s):
            if c not in inst:
                while st and st[-1] > c and last[st[-1]] > i:
                    top = st.pop()
                    inst.remove(top)
                st.append(c)
                inst.add(c)

        return "".join(st)