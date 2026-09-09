class Solution {
public:
    long long countCommas(long long n) {
        long long st=1000,cm=1,ans=0;
        while(st<=n){
            long long end=1000*st-1;
            if(end>n){end=n;}
            ans+=(end-st+1)*cm;
            st*=1000;
            cm++;
        }
        return ans;
    }
};