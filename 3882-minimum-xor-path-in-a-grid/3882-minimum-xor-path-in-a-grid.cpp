class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int or_all = 0;
        for (auto& row : grid) {
            for (int x : row) {
                or_all |= x;
            }
        }

        vector vis(m, vector(n, vector<int8_t>(or_all + 1)));
        int ans = INT_MAX;

        auto dfs = [&](this auto&& dfs, int i, int j, int xor_val) -> void {
            if (ans == 0 || i < 0 || j < 0 || vis[i][j][xor_val]) {
                return;
            }
            vis[i][j][xor_val] = true;
            xor_val ^= grid[i][j];
            if (i == 0 && j == 0) {
                ans = min(ans, xor_val);
                return;
            }
            dfs(i - 1, j, xor_val);
            dfs(i, j - 1, xor_val);
        };

        dfs(m - 1, n - 1, 0);
        return ans;
    }
};
