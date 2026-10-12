class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int& x:nums)x*=x; ranges::sort(nums); return accumulate(nums.begin(),nums.end(),0LL)-2*accumulate(nums.begin(),nums.begin()+nums.size()/2,0LL);
    }
};