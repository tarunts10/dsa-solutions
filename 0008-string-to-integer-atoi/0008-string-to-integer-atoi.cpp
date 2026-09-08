class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        long long ans=0;
        int n=s.length();
        int i=0;

        while(i<n &&s[i]==' '){
            i++;
        }

        if(i<n && ( s[i]=='+' || s[i]=='-')){
            if(s[i]=='+'){sign=1;}
            else{sign=-1;}
            i++;
        }

        while(i<n&& isdigit(s[i])){
            int digit=s[i]-'0';
            if(ans>(INT_MAX-digit)/10){
                if(sign==1){return INT_MAX;}
                else{return INT_MIN;}
            }
            ans = ans*10 + digit;
            i++;
        }
        return ans*sign;
    }
};