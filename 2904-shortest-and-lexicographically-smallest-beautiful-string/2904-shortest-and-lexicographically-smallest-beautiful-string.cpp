class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(ranges::count(s, '1') < k) return "";
        string ans = "";
        int l = 0, cnt = 0;
        for(int r = 0; r < s.size(); r++) 
        {
            if(s[r] == '1') cnt++;
            while(cnt > k)
            {
                if(s[l] == '1') cnt--;
                l++;
            }

            if(cnt == k) 
            {
                while(l <= r && s[l] == '0') l++;
                string cur = s.substr(l, r - l + 1);

                if(ans.empty() || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) ans = cur;
            }
        }
        return ans;
    }
};