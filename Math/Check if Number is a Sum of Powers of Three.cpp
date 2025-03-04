//Optimal Approach O(Log3(N))
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 1){
            while(n % 3 == 0){
                n /= 3;
            }
            if(n % 3 > 1){
                return false;
            }
            n--;
        }
        return true;
    }
};
