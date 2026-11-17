
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // 1. 預處理每個長度的合法因數 d
        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d <= n / 2; ++d) {
            for (int len = 2 * d; len <= n; len += d) {
                divisors[len].push_back(d);
            }
        }

        // 2. cost[i][j]：s[i...j] 變成半回文的最少修改次數
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;

                // 枚舉所有合法 d
                for (int d : divisors[len]) {
                    int changes = 0;

                    // 依照 index % d 分組
                    for (int offset = 0; offset < d; ++offset) {
                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        // 雙指標計算回文修改成本
                        while (l < r) {
                            if (s[l] != s[r]) {
                                ++changes;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // 3. 分割型 DP
        // dp[t][i]：前 i 個字元切成 t 段的最小成本
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int t = 1; t <= k; ++t) {
            for (int i = 2 * t; i <= n; ++i) {

                // 枚舉最後一段的起點 p
                for (int p = 2 * (t - 1); p <= i - 2; ++p) {
                    if (dp[t - 1][p] == INF) {
                        continue;
                    }

                    dp[t][i] = min(
                        dp[t][i],
                        dp[t - 1][p] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
