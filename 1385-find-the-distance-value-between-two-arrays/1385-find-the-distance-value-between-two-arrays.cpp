class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        ranges::sort(arr1);
        ranges::sort(arr2);
        int ans = 0, idx = 0;
        for(int x : arr1)
        {
            while(idx < arr2.size() && arr2[idx] < x-d) idx++;
            if(idx == arr2.size() || arr2[idx] > x+d) ans++;
        }
        return ans;
    }
};