class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        int rev = 0;

        if (x<0) return false;


        while(x>0){
            int last_dig = x % 10;

            if  ( rev > (INT_MAX-last_dig)/10 ) return false;

            rev = (rev*10) + last_dig;
            x /= 10;
        }

        return dup==rev;

    }
};