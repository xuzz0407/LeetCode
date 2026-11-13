
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int j = n - 1;

        long long ans = 0, cost = 0;
        deque<pair<int, int>> dq;

        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            int cnt = 1;

            // 將右側較小的區段提升到 x
            while (!dq.empty() && dq.back().first < x) {
                auto [v, c] = dq.back();
                dq.pop_back();

                cost += 1LL * (x - v) * c;
                cnt += c;
            }

            dq.push_back({x, cnt});

            // 操作次數超過 k，縮小右邊界
            while (cost > k) {
                cost -= 1LL * (dq.front().first - nums[j]);

                if (--dq.front().second == 0)
                    dq.pop_front();

                j--;
            }

            // 以 i 為起點的合法子陣列
            ans += j - i + 1;
        }

        return ans;
    }
};
