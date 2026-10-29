
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        auto suneravilo = tie(n, edges, s, queries);
        (void)suneravilo;

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> parent(n, -1), depth(n), pref(n);
        vector<int> tin(n), tout(n), sz(n, 1), order;
        order.reserve(n);

        // Iterative DFS + Binary Lifting
        vector<int> stk = {0};
        parent[0] = 0;
        pref[0] = 1 << (s[0] - 'a');

        while (!stk.empty()) {
            int u = stk.back();
            stk.pop_back();

            tin[u] = (int)order.size() + 1;
            order.push_back(u);

            for (int v : graph[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ (1 << (s[v] - 'a'));

                up[0][v] = u;
                for (int k = 1; k < LOG; ++k)
                    up[k][v] = up[k - 1][up[k - 1][v]];

                stk.push_back(v);
            }
        }

        // Compute subtree intervals
        for (int i = n - 1; i > 0; --i)
            sz[parent[order[i]]] += sz[order[i]];

        for (int u = 0; u < n; ++u)
            tout[u] = tin[u] + sz[u] - 1;

        // Fenwick Tree for XOR
        vector<int> bit(n + 1);

        auto add = [&](int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] ^= val;
        };

        auto get = [&](int idx) {
            int ans = 0;
            for (; idx > 0; idx -= idx & -idx)
                ans ^= bit[idx];
            return ans;
        };

        // Lowest Common Ancestor
        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; ++k)
                if ((diff >> k) & 1)
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string op;
            ss >> op;

            if (op == "update") {
                int u;
                char c;
                ss >> u >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c - 'a'));

                if (delta) {
                    add(tin[u], delta);
                    add(tout[u] + 1, delta);
                    s[u] = c;
                }
            } else {
                int u, v;
                ss >> u >> v;

                int w = lca(u, v);

                int mask = pref[u] ^ get(tin[u]) ^
                           pref[v] ^ get(tin[v]) ^
                           (1 << (s[w] - 'a'));

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
