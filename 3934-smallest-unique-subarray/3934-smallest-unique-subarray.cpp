class Solution {
    static constexpr uint64_t M = (1ULL << 61) - 1;  
    static uint64_t mul(uint64_t a, uint64_t b) {
        __uint128_t p = (__uint128_t)a * b;
        uint64_t r = (uint64_t)(p & M) + (uint64_t)(p >> 61);
        return r >= M ? r - M : r;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        uint64_t B = rng() % (M - 200000) + 100001;  

        vector<uint64_t> pw(n + 1, 1), pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pw[i + 1] = mul(pw[i], B);
            pre[i + 1] = (mul(pre[i], B) + nums[i]) % M;
        }

        vector<uint64_t> h;
        auto hasUnique = [&](int L) {
            h.clear();
            for (int i = 0; i + L <= n; ++i)
                h.push_back((pre[i + L] + M - mul(pre[i], pw[L])) % M);
            sort(h.begin(), h.end());
            for (size_t i = 0, j; i < h.size(); i = j) {
                j = i;
                while (j < h.size() && h[j] == h[i]) ++j;
                if (j - i == 1) return true;        
            }
            return false;
        };

        int lo = 1, hi = n;                       
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (hasUnique(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};