class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while (x!=0){
            int last_dig = x % 10;
            x /= 10;
            rev = (rev*10) + last_dig;

            if (rev>INT_MAX || rev<INT_MIN) return 0;
        }
        return rev;
        
    }
};