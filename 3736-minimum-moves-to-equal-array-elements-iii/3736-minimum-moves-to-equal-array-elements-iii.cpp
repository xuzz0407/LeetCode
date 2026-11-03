class Solution {
public:
    int minMoves(vector<int>& nums) {
        return ranges::max(nums) * nums.size() - reduce(nums.begin(), nums.end(), 0);
    }
};