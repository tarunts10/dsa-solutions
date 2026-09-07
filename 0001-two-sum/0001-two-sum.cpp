class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int n=nums[i];
            int moreNeeded=target-n;
            if(mp.find(moreNeeded)!=mp.end()){
                return {mp[moreNeeded],i};
            }
            mp[n]=i;
        }
        return {-1,-1};
    }
};