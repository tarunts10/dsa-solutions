class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        /*int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2!=0){
                    cnt++;
                }
                if(cnt==k){
                    ans++;
                    
                }
            }
        }
        return ans;*/

        int n=nums.size();
        int ans=0;
        int odd=0;
        int left=0;

        for(int right=0;right<n;right++){
            if(nums[right]%2!=0){
                odd++;
            }

            while(odd>k){
                if(nums[left]%2!=0){
                    odd--;
                }
                left++;
            }

            ans += right-left+1;
        }

        int ans2=0;
        odd=0;
        left=0;

        for(int right=0;right<n;right++){
            if(nums[right]%2!=0){
                odd++;
            }

            while(odd>k-1){
                if(nums[left]%2!=0){
                    odd--;
                }
                left++;
            }

            ans2 += right-left+1;
        }

        return ans-ans2;
    }
};