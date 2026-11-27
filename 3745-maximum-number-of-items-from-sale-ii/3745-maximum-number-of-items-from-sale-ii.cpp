class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> cnt(n + 1), mul(n + 1);
        for (auto& it : items) cnt[it[0]]++;
        for (int d = 1; d <= n; d++)
            for (int k = d; k <= n; k += d) mul[d] += cnt[k];

        vector<pair<long long, long long>> v;   // {price, 可換贈品次數 c}
        long long m = LLONG_MAX;
        for (auto& it : items) {
            v.push_back({it[1], mul[it[0]] - 1});
            m = min(m, (long long)it[1]);
        }
        sort(v.begin(), v.end());

        long long B = budget, ans = 0;
        for (auto [p, c] : v) {
            if (p >= 2 * m) break;           // 買一送一已不比單買 m 划算
            long long t = min(c, B / p);
            ans += 2 * t, B -= t * p;
            if (t < c) break;                // 預算不夠，後面只會更貴
        }
        return ans + B / m;                  // 剩下的錢全買最便宜的
    }
};