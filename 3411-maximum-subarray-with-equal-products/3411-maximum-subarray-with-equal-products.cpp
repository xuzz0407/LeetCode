class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=2, p=1, l=0;
        for(auto [r,x]:views::enumerate(nums))while(gcd(p,x)-1?p/=nums[l++],true:(p*=x,ans=max(ans,int(r)-l+1),false));
        return ans;
    }
};