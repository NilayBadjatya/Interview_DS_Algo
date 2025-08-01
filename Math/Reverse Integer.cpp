class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        if(x == INT_MIN || x == INT_MAX){
            return 0;
        }
        bool nega = false;
        if(x < 0){
            nega = true;
        }
        x = abs(x);
        while(x > 0){
            int r = x % 10;
            if(rev > INT_MAX / 10 || rev > (INT_MAX - r) / 10){
                return 0;
            }
            rev = rev * 10 + r;
            x = x / 10;
        }
        if(nega){
            return -rev;
        }
        return rev;
    }
};
