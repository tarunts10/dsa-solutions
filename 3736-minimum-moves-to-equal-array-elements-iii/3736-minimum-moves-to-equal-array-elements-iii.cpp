class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        int max=*max_element(nums.begin(),nums.end());

        int ans=0;

        for(int i=0;i<n;i++){
            int x=max-nums[i];
            ans+=x;
        }
        return ans;
    }
};