class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        vector dis(n, vector<int>(k + 1, INT_MAX));
        // tuple{最短路长度, 节点编号, 最后连续相同字母个数}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, x, cnt] = pq.top();
            pq.pop();
            if (x == n - 1) {
                return d;
            }
            if (d > dis[x][cnt]) {
                continue;
            }
            for (auto& [y, w] : g[x]) {
                int new_cnt = labels[y] == labels[x] ? cnt + 1 : 1;
                int new_dis = d + w;
                if (new_cnt <= k && new_dis < dis[y][new_cnt]) {
                    dis[y][new_cnt] = new_dis;
                    pq.emplace(new_dis, y, new_cnt);
                }
            }
        }

        return -1;
    }
};