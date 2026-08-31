class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int cnt = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }

        int target = (1 << cnt) - 1;

        // best[mask][pos] = 最大剩餘能量
        vector<vector<int>> best(
            1 << cnt,
            vector<int>(m * n, -1)
        );

        // r, c, mask, energy
        queue<array<int, 4>> q;

        q.push({sr, sc, 0, energy});
        best[0][sr * n + sc] = energy;

        int dirs[5] = {1, 0, -1, 0, 1};
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == target)
                    return step;

                // 沒能量就不能再走
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d];
                    int nc = c + dirs[d + 1];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // 撿垃圾
                    if (classroom[nr][nc] == 'L') {
                        nmask |= 1 << id[nr][nc];
                    }

                    // 進入 R 後能量補滿
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int pos = nr * n + nc;

                    // 已經用更多 energy 到過相同狀態
                    if (best[nmask][pos] >= ne)
                        continue;

                    best[nmask][pos] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }

            step++;
        }

        return -1;
    }
};