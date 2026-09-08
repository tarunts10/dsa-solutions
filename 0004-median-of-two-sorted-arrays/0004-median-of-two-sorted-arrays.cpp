class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       /*double ans;
       int s=nums1.size()+nums2.size();
       vector<int> arr;

       for(int i=0;i<nums1.size();i++){
            arr.push_back(nums1[i]);
       }
       for(int j=0;j<nums2.size();j++){
            arr.push_back(nums2[j]);
       } 
        sort(arr.begin(),arr.end());

       if(s%2==1){
        return arr[s/2];

       }
       else{
        return (arr[s/2-1]+arr[s/2])/2.0;

       }
*/

        
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
            //Always BS on smaller array
        }
        int low=0,high=n1;

        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;

            int lef1=cut1==0?INT_MIN:nums1[cut1-1];
            int lef2=cut2==0?INT_MIN:nums2[cut2-1];

            int rig1=cut1==n1?INT_MAX:nums1[cut1];
            int rig2=cut2==n2?INT_MAX:nums2[cut2];

            if(lef1<=rig2&&lef2<=rig1){
                if((n1+n2)%2==0){
                    return (max(lef1,lef2)+min(rig1,rig2))/2.0;
                }
                else{
                    return max(lef1,lef2);
                }
            }
            else if(lef1>rig2){
                high=cut1-1;
                
            }
            else{
                low=cut1+1;
            }
        }
        return 0.0;

    }
};