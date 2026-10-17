class DSU {
public:
    vector<int> parent, sz;
    vector<long long> ways;
    int cnt;

    DSU(int n): parent(n), sz(n, 1), ways(n, 1), cnt(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        parent[ry] = rx;
        sz[rx] += sz[ry];
        cnt--;
    }
};

class Solution {
private:
    static constexpr long long mod = 1e9 + 7;
    long long power(long long a, long long b) {
        long long res = 1;
        while(b) {
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);
        vector<long long> f(n+1, 1), inv(n+1, 1);
        for(int i = 1; i <= n; i++) f[i] = f[i-1] * i % mod;
        inv[n] = power(f[n], mod-2);
        for(int i = n; i >= 1; i--) inv[i-1] = inv[i] * i % mod;
        vector<int> a = nums;
        sort(a.begin(), a.end());
        vector<bool> ok(n, false);

        for(int k = n-1; k >= 0; k--) {
            int i = lower_bound(a.begin(), a.end(), nums[k]) - a.begin();
            int l = i > 0 && ok[i-1] ? dsu.find(i-1) : -1,r = i+1 < n && ok[i+1] ? dsu.find(i+1) : -1;
            int lo = l == -1 ? 0 : dsu.sz[l], hi = r == -1 ? 0 : dsu.sz[r];
            long long cur = f[lo+hi] * inv[lo] % mod * inv[hi] % mod;
            if(l != -1) cur = cur * dsu.ways[l] % mod;
            if(r != -1) cur = cur * dsu.ways[r] % mod;
            ok[i] = true;
            dsu.ways[i] = cur;
            if(l != -1) dsu.unite(i, l);
            if(r != -1) dsu.unite(i, r);
        }

        return (dsu.ways[dsu.find(0)] - 1 + mod) % mod;
    }
};