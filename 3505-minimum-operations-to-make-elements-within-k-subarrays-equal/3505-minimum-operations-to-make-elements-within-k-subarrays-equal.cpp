
class Solution {
    struct MedianWindow {
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        void balance() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                int v = *it;

                sumLow -= v;
                low.erase(it);

                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                auto it = high.begin();
                int v = *it;

                sumHigh -= v;
                high.erase(it);

                low.insert(v);
                sumLow += v;
            }
        }

        void add(int v) {
            if (low.empty() || v <= *low.rbegin()) {
                low.insert(v);
                sumLow += v;
            } else {
                high.insert(v);
                sumHigh += v;
            }
            balance();
        }

        void remove(int v) {
            auto it = low.find(v);

            if (it != low.end()) {
                sumLow -= v;
                low.erase(it);
            } else {
                it = high.find(v);
                sumHigh -= v;
                high.erase(it);
            }
            balance();
        }

        long long cost() const {
            long long mid = *low.rbegin();

            return mid * low.size() - sumLow
                 + sumHigh - mid * high.size();
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // 題目指定的變數
        vector<int> maritovexi = nums;

        MedianWindow window;

        // 建立第一個視窗
        for (int i = 0; i < x; ++i)
            window.add(maritovexi[i]);

        // 預先計算每個視窗的最小成本
        vector<long long> cost(n - x + 1);
        cost[0] = window.cost();

        for (int i = 1; i + x <= n; ++i) {
            window.remove(maritovexi[i - 1]);
            window.add(maritovexi[i + x - 1]);
            cost[i] = window.cost();
        }

        // DP：選擇 k 個互不重疊子陣列
        const long long INF = LLONG_MAX / 4;

        vector<long long> prevDP(n + 1, 0);
        vector<long long> currDP(n + 1, INF);

        for (int j = 1; j <= k; ++j) {
            fill(currDP.begin(), currDP.end(), INF);

            for (int i = x; i <= n; ++i) {
                // 不選擇目前結尾的視窗
                currDP[i] = currDP[i - 1];

                // 選擇 [i-x, i-1]
                if (prevDP[i - x] != INF) {
                    currDP[i] = min(
                        currDP[i],
                        prevDP[i - x] + cost[i - x]
                    );
                }
            }

            swap(prevDP, currDP);
        }

        return prevDP[n];
    }
};
