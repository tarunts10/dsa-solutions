class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int maxP=INT_MIN;
        for(int i=0;i<n;i++){
            int prod=nums[i];
            maxP=max(maxP,prod);
            for(int j=i+1;j<n;j++){
                prod*=nums[j];
                maxP=max(maxP,prod);
            }

        }
        return maxP;
        
    }
};