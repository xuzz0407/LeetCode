class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans(count(nums.begin(),nums.end(),target)); 
        iota(ans.begin(),ans.end(),count_if(nums.begin(),nums.end(),[&](int x){return x<target;})); 
        return ans;
    }
};