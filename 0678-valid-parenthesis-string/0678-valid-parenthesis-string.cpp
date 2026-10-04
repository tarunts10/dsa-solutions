class Solution {
public:
    bool checkValidString(string s) {
        int l=0,h=0;
        int len=s.length();

        for(int i=0;i<len;i++){
            char ch=s[i];
            if(ch=='('){
                l++;
                h++;
            }
            else if(ch==')'){
                h--;
                l--;
            }
            else{
                l--;
                h++;
            }
            if(l<0){
                l=0;
            }
            if(h<0){
                return false;
            }
        }
        return l==0;

    }
};