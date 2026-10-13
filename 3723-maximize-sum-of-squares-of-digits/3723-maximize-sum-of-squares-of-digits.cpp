class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        return sum > 9 * num ? "" : string(sum/9,'9') + (sum % 9 ? to_string(sum%9) : "") + string(num - (sum+8) / 9, '0');
    }
};