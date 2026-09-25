class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxS=-1;
        for(int i=0;i<m-2;i++){
            int s=0;
            for(int j=0;j<n-2;j++){
                s=grid[i][j]+grid[i][j+1]+grid[i][j+2]
                    +grid[i+1][j+1]
                    +grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                maxS=max(s,maxS);
            }

        }
        return maxS;
    }
};