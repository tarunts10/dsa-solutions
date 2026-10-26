class Solution {
public:
    long long bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int k, int s, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y] = 1;

        long long sum = 0;

        int dr[4] = {0,0,-1,1};
        int dc[4] = {1,-1,0,0};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            sum += grid[r][c];

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   grid[nr][nc] > 0 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0 && !vis[i][j]) {
                    long long s = bfs(grid, vis, k, 0, i, j);

                    if(s % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};