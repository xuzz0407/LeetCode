class Solution {
    private int[] m;
    private boolean dfs(int x)
    {
        if(x == 0) return false;
        if(m[x] != 0) return m[x] == 1;
        for(int i = 1; i * i <= x; i++)
        {
            if(!dfs(x - i * i))
            {
                m[x] = 1;
                return true;
            }
        }

        m[x] = -1;
        return false;
    }

    public boolean winnerSquareGame(int n) {
        m = new int[n+1];
        return dfs(n);
    }
}