class Solution {
public:
    int minOperations(string s) {
        if(ranges::is_sorted(s)) return 0;
        int len = s.size();
        if(len == 2) return -1;
        auto [x, y] = ranges::minmax(s);
        if(s[0] == x || s[len-1] == y) return 1;
        for(int i = 1; i < len-1; i++) if(s[i] == x || s[i] == y) return 2;
        return 3;
    }
};