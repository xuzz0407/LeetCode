class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26);

        for(char c : s)
            cnt[c - 'a']++;

        auto quinorath = make_pair(s, target);

        string ans;

        for(int i = 0; i < n; i++)
        {
            int t = target[i] - 'a';

            // 盡量跟 target 一樣
            if(cnt[t] > 0)
            {
                ans += target[i];
                cnt[t]--;
                continue;
            }

            // 無法一樣，找最小的 > target[i]
            for(int c = t + 1; c < 26; c++)
            {
                if(cnt[c] > 0)
                {
                    ans += char('a' + c);
                    cnt[c]--;

                    // 已經比 target 大
                    // 剩下全部由小到大塞
                    for(int j = 0; j < 26; j++)
                        ans += string(cnt[j], char('a' + j));

                    return ans;
                }
            }

            // 目前位置無法讓答案變大
            // 往前 backtrack
            for(int j = i - 1; j >= 0; j--)
            {
                int old = target[j] - 'a';

                // 把原本使用的 target[j] 放回去
                cnt[old]++;
                ans.pop_back();

                // 嘗試把這個位置變大
                for(int c = old + 1; c < 26; c++)
                {
                    if(cnt[c] > 0)
                    {
                        ans += char('a' + c);
                        cnt[c]--;

                        for(int k = 0; k < 26; k++)
                            ans += string(cnt[k], char('a' + k));

                        return ans;
                    }
                }
            }

            return "";
        }

        // ans == target
        // 但題目要求 strictly greater
        // 所以還要往前找一位增加
        for(int i = n - 1; i >= 0; i--)
        {
            int old = target[i] - 'a';

            cnt[old]++;
            ans.pop_back();

            for(int c = old + 1; c < 26; c++)
            {
                if(cnt[c] > 0)
                {
                    ans += char('a' + c);
                    cnt[c]--;

                    for(int j = 0; j < 26; j++)
                        ans += string(cnt[j], char('a' + j));

                    return ans;
                }
            }
        }

        return "";
    }
};