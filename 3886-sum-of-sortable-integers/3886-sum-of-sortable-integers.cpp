
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        auto check = [&](int k) {
            int prev = INT_MIN;

            for (int i = 0; i < n; i += k) {
                int mn = INT_MAX, mx = INT_MIN, drops = 0;

                for (int j = i; j < i + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    if (nums[j] > nums[j + 1 < i + k ? j + 1 : i])
                        drops++;
                }

                if (drops > 1 || prev > mn) return false;
                prev = mx;
            }
            return true;
        };

        for (int k = 1; k * k <= n; k++) {
            if (n % k) continue;

            if (check(k)) ans += k;
            if (k * k != n && check(n / k))
                ans += n / k;
        }

        return ans;
    }
};
