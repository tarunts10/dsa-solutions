class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int s=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int dist=0;
            int a[101]={0};
            for(int j=i;j<n;j++){
                if(a[nums[j]]==0){
                    dist++;
                }
                a[nums[j]]++;
                s+=(dist*dist);
            }
            
        }
        return s;
    }
};