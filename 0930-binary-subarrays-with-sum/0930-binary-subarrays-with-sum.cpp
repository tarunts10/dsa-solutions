class Solution {
public:
    int calc(vector<int> &nums,int goal){
        if(goal<0){return 0;}
        int r=0,l=0,sum=0;
        int n=nums.size();
        int cnt=0;

        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calc(nums,goal)-calc(nums,goal-1);
        /*int cnt=0,n=nums.size();
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                if(s==goal){
                    cnt++;
                }
            }
        }
        return cnt;*/
    }
};