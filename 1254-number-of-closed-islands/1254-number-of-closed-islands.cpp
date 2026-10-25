class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc] == 0) {
                dfs(nr, nc, grid, vis);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 0 && !vis[i][j]) {
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return cnt;
    }
};