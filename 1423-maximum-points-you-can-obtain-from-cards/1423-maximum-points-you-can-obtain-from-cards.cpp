class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rSum=0,lSum=0,n=cardPoints.size();
        for(int i=0;i<k;i++){
            lSum+=cardPoints[i];

        }
        int maxS=lSum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            lSum-=cardPoints[i];
            rSum+=cardPoints[r];
            r--;
            maxS=max(maxS,lSum+rSum);
        }

        return maxS;
    }
};