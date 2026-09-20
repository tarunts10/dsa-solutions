class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int y=0;
        
        for(int i=0;i<n;i++){
            int x='z'-s[i]+1;
            y+=x*(i+1);
        }
        return y;

    }
};