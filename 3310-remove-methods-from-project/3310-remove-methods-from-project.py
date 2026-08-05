class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        gp = [[]  for _ in range(n)]
        for x, y in invocations:
            gp[x].append(y)

        sus = [False] * n
    
        def dfs(x: int) -> None:
            sus[x] = True

            for y in gp[x]:
                if not sus[y]:
                    dfs(y)
        
        dfs(k)

        for x, y in invocations:
            if not sus[x] and sus[y]:
                return list(range(n))
        
        return [i for i, x in enumerate(sus) if not x]
            