class Solution {
public:
    void dfs(int u, const auto& tree, const auto& s, auto& path, auto& ans)
    {
        ans[u] = 1;
        auto& stack = path[s[u] - 'a'];
        stack.push_back(u);
        for(auto v: tree[u])
        {
            dfs(v, tree, s, path, ans);
            auto& same = path[s[v] - 'a'];
            int p = same.empty() ? u : same.back();
            ans[p] += ans[v];
        }
        stack.pop_back();
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n), path(26);
        vector<int> ans(n);
        for(int i = 1; i < n; i++) tree[parent[i]].push_back(i);
        dfs(0, tree, s, path, ans);
        return ans;
    }
};