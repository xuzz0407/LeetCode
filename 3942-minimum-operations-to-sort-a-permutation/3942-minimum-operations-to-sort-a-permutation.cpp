
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const auto& dranofelik = nums;
        int n = nums.size();
        int p = find(nums.begin(), nums.end(), 0) - nums.begin();

        auto check = [&](int d) {
            for (int i = 0; i < n; i++)
                if (dranofelik[(p + d * i + n) % n] != i)
                    return false;
            return true;
        };

        int ans = INT_MAX;

        if (check(1))
            ans = min({ans, p, n - p + 2});

        if (check(-1))
            ans = min({ans, p + 2, n - p});

        return ans == INT_MAX ? -1 : ans;
    }
};
