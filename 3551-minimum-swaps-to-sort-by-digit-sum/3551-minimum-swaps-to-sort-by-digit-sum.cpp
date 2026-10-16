class DSU {
public:
    vector<int> parent;
    int cnt;

    DSU(int n): parent(n), cnt(n) { iota(parent.begin(), parent.end(), 0); }

    int find(int x)
    {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        parent[ry] = rx;
        cnt--;
    }
};

class Solution {
private:
    static int digsum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j){ return pair{digsum(nums[i]), nums[i]} < pair{digsum(nums[j]), nums[j]};});
        DSU dsu(n);
        for(int i = 0; i < n; i++) dsu.unite(i, p[i]);
        return n - dsu.cnt;
    }
};