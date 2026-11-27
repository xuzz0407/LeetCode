class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int M = 1500;
        vector<int> freq(M + 1), mul(M + 1);
        int pmin = INT_MAX;
        for (auto& it : items) freq[it[0]]++, pmin = min(pmin, it[1]);

        // mul[f]：有幾個 factor 是 f 的倍數（包含自己）
        for (int f = 1; f <= M; f++)
            for (int m = f; m <= M; m += f) mul[f] += freq[m];

        // dp[c]：花費剛好 c 時的最大份數，-1 表示湊不出來
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for (auto& it : items) {
            int p = it[1], v = mul[it[0]];   // 1 + (mul - 1) = mul
            for (int c = budget; c >= p; c--)
                if (dp[c - p] >= 0) dp[c] = max(dp[c], dp[c - p] + v);
        }

        int ans = 0;
        for (int c = 0; c <= budget; c++)
            if (dp[c] >= 0) ans = max(ans, dp[c] + (budget - c) / pmin);
        return ans;
    }
};