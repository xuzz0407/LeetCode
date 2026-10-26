
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int d[5] = {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!grid[i][j]) continue;

                long long sum = grid[i][j];
                grid[i][j] = 0;

                stack<pair<int, int>> st;
                st.push({i, j});

                while(!st.empty()) {
                    auto [x, y] = st.top();
                    st.pop();

                    for(int t = 0; t < 4; t++) {
                        int nx = x + d[t], ny = y + d[t + 1];

                        if(nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny])
                            continue;

                        sum += grid[nx][ny];
                        grid[nx][ny] = 0;
                        st.push({nx, ny});
                    }
                }

                ans += (sum % k == 0);
            }
        }
        return ans;
    }
};
