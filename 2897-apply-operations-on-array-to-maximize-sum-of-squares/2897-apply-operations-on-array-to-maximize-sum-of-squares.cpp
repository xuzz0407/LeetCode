class Solution {
public:
    int maxSum(vector<int> &nums, int k) {
        const int MOD = 1'000'000'007;
        int cnt[30]{};
        for (int x: nums) {
            for (int i = 0; i < 30; i++) {
                cnt[i] += (x >> i) & 1;
            }
        }
        long long ans = 0;
        while (k--) {
            int x = 0;
            for (int i = 0; i < 30; i++) {
                if (cnt[i] > 0) {
                    cnt[i]--;
                    x |= 1 << i;
                }
            }
            ans = (ans + (long long) x * x) % MOD;
        }
        return ans;
    }
};