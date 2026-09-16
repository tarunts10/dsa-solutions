class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*int n=nums.size();
        int maxLen=0;

        for(int i=0;i<n;i++){
            int zeros=0;
            int len=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeros++;
                }
                if(zeros<=k){
                    len=j-i+1;
                    maxLen=max(maxLen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxLen;*/

        int n=nums.size();
        int l=0,r=0,maxLen=0,zeros=0;
        int len=0;
        while(r<n){
            if(nums[r]==0){zeros++;}
            if(zeros>k){
                if(nums[l]==0){zeros--;}
                l++;
            }
            if(zeros<=k){
                len=r-l+1;
                maxLen=max(maxLen,len);
            }
            r++;
        }
        return maxLen;
    }
};