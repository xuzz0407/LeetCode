class Solution {
    private int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x % y);
    }

    public long gcdSum(int[] nums) {
        int n = nums.length;
        int[] pre = new int[n];
        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            mx = Math.max(mx, nums[i]);
            pre[i] = gcd(nums[i], mx);
        }

        Arrays.sort(pre);
        long ans = 0;

        for(int l = 0, r = n-1; l < r; l++, r--)
            ans += gcd(pre[l], pre[r]);
        
        return ans;
    }
}