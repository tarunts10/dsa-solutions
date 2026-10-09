class Solution {
public:

    void dfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[r][c]=1;

        int n=grid.size();
        int m=grid[0].size();

        //4 directions acc to question up,down,left,right

        int dc[]={-1,1,0,0};
        int dr[]={0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis);
            }
        }

    }
    void bfs(int r,int c,vector<vector<char>> grid,vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[r][c]=1;

        queue<pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            int dr[]={-1,1,0,0};
            int dc[]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        /*vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid,vis);
                }
            }
        }

        return cnt;*/

        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;

    }
};