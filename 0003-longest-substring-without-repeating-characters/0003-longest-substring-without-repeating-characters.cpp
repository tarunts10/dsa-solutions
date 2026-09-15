class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        /*int maxLen=0;

        for(int i=0;i<n;i++){
            vector<int> hash(256,0);
            int len=0;
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1){break;}
                len=j-i+1;
                maxLen=max(maxLen,len);
                hash[s[j]]=1;
            }
        }
        return maxLen;*/
        int r=0,l=0,maxLen=0;
        vector<int> hash(256,-1);
        
        while(r<n){
            int len=0;
            if(hash[s[r]]!=-1){
                l=max(l,hash[s[r]]+1);
            }
            len=r-l+1;
            maxLen=max(maxLen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};