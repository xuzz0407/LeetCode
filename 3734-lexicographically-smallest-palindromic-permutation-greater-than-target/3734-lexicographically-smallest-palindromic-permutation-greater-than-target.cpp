class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);

        for(char c : s)
            cnt[c - 'a']++;

        // 檢查能不能組成 palindrome
        int odd = 0;
        char mid = 0;

        for(int i = 0; i < 26; i++)
        {
            if(cnt[i] % 2)
            {
                odd++;
                mid = 'a' + i;
            }
        }

        if(odd > 1)
            return "";

        // 左半邊需要的字元數量
        vector<int> half(26);

        for(int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string center = "";

        if(n % 2)
            center += mid;

        auto buildPalindrome = [&](string left)
        {
            string right = left;
            reverse(right.begin(), right.end());

            return left + center + right;
        };

        string t = target.substr(0, m);

        // ------------------------------------------------
        // Case 1:
        // 左半邊可以完全跟 target 左半邊一樣
        // ------------------------------------------------
        vector<int> rem = half;

        bool same = true;

        for(char c : t)
        {
            int x = c - 'a';

            if(rem[x] == 0)
            {
                same = false;
                break;
            }

            rem[x]--;
        }

        if(same)
        {
            string ans = buildPalindrome(t);

            // 左半相同時，要比較 center + right
            if(ans > target)
                return ans;
        }

        // ------------------------------------------------
        // Case 2:
        // 找「最小的左半排列 > target 左半」
        // ------------------------------------------------
        rem = half;

        string prefix = "";

        int fail = m;

        // 先盡量和 target 左半保持相同
        for(int i = 0; i < m; i++)
        {
            int x = t[i] - 'a';

            if(rem[x] > 0)
            {
                rem[x]--;
                prefix += t[i];
            }
            else
            {
                fail = i;
                break;
            }
        }

        // 建立：
        // prefix + 一個比 target[pos] 大的最小字元 + 剩下升冪
        auto makeAnswer = [&](int pos) -> string
        {
            int x = t[pos] - 'a';

            for(int c = x + 1; c < 26; c++)
            {
                if(rem[c] == 0)
                    continue;

                rem[c]--;

                string left = prefix;
                left += char('a' + c);

                // 剩下全部放最小排列
                for(int j = 0; j < 26; j++)
                {
                    left += string(rem[j], 'a' + j);
                }

                rem[c]++;

                return buildPalindrome(left);
            }

            return "";
        };

        // 如果是在 fail 位置無法 match
        // 先看看這一格能不能直接變大
        if(fail < m)
        {
            string ans = makeAnswer(fail);

            if(!ans.empty())
                return ans;
        }

        // ------------------------------------------------
        // 無法在 fail 位置變大
        // 往前 backtrack
        // ------------------------------------------------
        int i;

        if(fail < m)
            i = fail - 1;
        else
            i = m - 1;

        for(; i >= 0; i--)
        {
            // 把原本 match 的字元放回去
            int x = t[i] - 'a';

            rem[x]++;
            prefix.pop_back();

            string ans = makeAnswer(i);

            if(!ans.empty())
                return ans;
        }

        return "";
    }
};