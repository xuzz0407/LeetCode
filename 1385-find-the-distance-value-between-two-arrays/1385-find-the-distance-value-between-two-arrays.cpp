class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        return count_if(arr1.begin(), arr1.end(), [&](int x) { return all_of(arr2.begin(), arr2.end(), [&](int y) { return abs(x - y) > d; }); });
    }
};