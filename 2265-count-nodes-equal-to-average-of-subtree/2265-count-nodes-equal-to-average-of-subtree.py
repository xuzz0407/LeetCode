class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        ans = 0

        def dfs(node):
            nonlocal ans
            
            if node is None:
                return 0, 0

            lsum, lcnt = dfs(node.left)
            rsum, rcnt = dfs(node.right)

            total = lsum + rsum + node.val
            cnt = lcnt + rcnt + 1

            if total // cnt == node.val:
                ans += 1

            return total, cnt
        
        dfs(root)

        return ans