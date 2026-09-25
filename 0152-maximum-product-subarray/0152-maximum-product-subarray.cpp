class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*int n=nums.size();
        
        int maxP=INT_MIN;
        for(int i=0;i<n;i++){
            int prod=nums[i];
            maxP=max(maxP,prod);
            for(int j=i+1;j<n;j++){
                prod*=nums[j];
                maxP=max(maxP,prod);
            }

        }
        return maxP;*/
        int n=nums.size();

        int prevMax=nums[0],prevMin=nums[0];
        int ans=nums[0];
        
        for(int i=1;i<n;i++){

            int maxCurr=max(nums[i],max(nums[i]*prevMin,nums[i]*prevMax));
            int minCurr=min(nums[i],min(nums[i]*prevMin,nums[i]*prevMax));
            ans=max(ans,maxCurr);
            prevMax=maxCurr;
            prevMin=minCurr;
        }
        return ans;
        
    }
};