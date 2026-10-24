class Solution {
    // 每月天数的前缀和（注：最后一个数可以省略）
    static constexpr int days_pre_sum[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

    int calc_days(string s) {
        int month = (s[0] - '0') * 10 + s[1] - '0';
        int day = (s[3] - '0') * 10 + s[4] - '0';
        return days_pre_sum[month - 1] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int left = calc_days(max(arriveAlice, arriveBob)); // 直接比较字符串再计算
        int right = calc_days(min(leaveAlice, leaveBob));
        return max(right - left + 1, 0); // 答案不能为负数
    }
};