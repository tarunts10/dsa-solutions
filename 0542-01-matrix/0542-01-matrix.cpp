class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> dist(n,vector<int> (m,0));
        vector<vector<int>> vis(n,vector<int> (m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int st=q.front().second;
            q.pop();
            dist[r][c]=st;

            int dr[4]={0,0,-1,1};
            int dc[4]={1,-1,0,0};

            for(int i=0;i<4;i++){
                int nr=dr[i]+r;
                int nc=dc[i]+c;
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]!=1){
                    q.push({{nr,nc},st+1});
                    vis[nr][nc]=1;
                }
            }
        }
        return dist;
    }
};