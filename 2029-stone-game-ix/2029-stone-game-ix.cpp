class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for(int x: stones) cnt[x%3]++;
        if(cnt[0] % 2 == 0)
        {
            if(cnt[1] && cnt[2]) return true;
            return false;
        }    
        return abs(cnt[1] - cnt[2]) > 2;
    } 
};