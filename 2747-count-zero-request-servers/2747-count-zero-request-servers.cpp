
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> qs;
        for (int i = 0; i < queries.size(); i++)
            qs.push_back({queries[i], i});

        sort(qs.begin(), qs.end());

        vector<int> cnt(n + 1, 0);
        vector<int> ans(queries.size());

        int left = 0, right = 0, active = 0;

        for (auto [q, idx] : qs) {

            // 加入視窗內的新請求
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right][0];

                if (cnt[id]++ == 0)
                    active++;

                right++;
            }

            // 移除已過期的請求
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left][0];

                if (--cnt[id] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};
