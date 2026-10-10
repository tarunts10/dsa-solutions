class Solution {
public:
    /*void dfs(const vector<vector<int>>& image,vector<vector<int>> &ans,int sr,int sc,int color,const int initColor){
        int n=image.size();
        int m=image[0].size();

        int dr[4]={0,0,-1,1};
        int dc[4]={1,-1,0,0};

        ans[sr][sc]=color;

        for(int i=0;i<4;i++){
            int nr=sr+dr[i];
            int nc=sc+dc[i];

            if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==initColor&&ans[nr][nc]!=color){
                dfs(image,ans,nr,nc,color,initColor);
            }
        }
    }*/

    void bfs(const vector<vector<int>>& image,vector<vector<int>> &ans,int sr,int sc,int color,const int initColor){

        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc]=color;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,1,-1};

        while(!q.empty()){
            

            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==initColor&&ans[nr][nc]!=color){
                    ans[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor=image[sr][sc];

        if(initColor==color){return image;}

        vector<vector<int>> ans=image;

        bfs(image,ans,sr,sc,color,initColor);

        return ans;
    }
};