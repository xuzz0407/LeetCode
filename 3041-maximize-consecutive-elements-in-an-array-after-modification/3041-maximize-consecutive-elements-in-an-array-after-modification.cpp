class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> f;
        int ans = 0;
        for (int x : nums) 
        {
            f[x+1] = f[x] + 1;
            f[x] = f[x-1] + 1;
            ans = max({ans, f[x], f[x+1]});
        }
        return ans;
    }
};
