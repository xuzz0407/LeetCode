class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        const auto& vornadexil = grid;

        vector<int> right(n, 0), down(n, 0);

        right[0] = down[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                int a = j > 0 ? right[j - 1] : 0;
                int b = i > 0 ? down[j] : 0;

                if (vornadexil[i][j] == 0) {
                    int total = (a + b) % MOD;
                    right[j] = total;
                    down[j] = total;
                } else {
                    right[j] = b;
                    down[j] = a;
                }
            }
        }

        return right[n - 1];
    }
};