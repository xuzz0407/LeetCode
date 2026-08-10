class Solution {
private:
    vector<int> memo;

    bool dfs(int x) 
    {
        if(x == 0) return false;

        if(memo[x] != 0)  return memo[x] == 1;

        for(int i = 1; i * i <= x; i++) 
        {
            if(!dfs(x - i * i)) 
            {
                memo[x] = 1;
                return true;
            }
        }

        memo[x] = -1;
        return false;
    }

public:
    bool winnerSquareGame(int n) {
        memo.assign(n + 1, 0);
        return dfs(n);
    }
};