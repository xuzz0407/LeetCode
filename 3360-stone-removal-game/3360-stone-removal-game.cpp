class Solution {
public:
    bool canAliceWin(int n, int i = 10) {
        return n >= i && !canAliceWin(n-i, i-1);
    }
};