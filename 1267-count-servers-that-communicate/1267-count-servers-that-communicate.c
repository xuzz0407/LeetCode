int countServers(int** g, int m, int* gridColSize) {
    int n = gridColSize[0], r[m], c[n], ans = 0;
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if (g[i][j]) r[i]++, c[j]++;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            ans += g[i][j] && (r[i] > 1 || c[j] > 1);

    return ans;
}
