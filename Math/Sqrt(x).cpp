// Approach 1: Time Complexity - O(sqrt(N))
typedef long long ll;
class Solution {
public:
    int mySqrt(int x) {
        ll i;
        for(i = 1; i * i <= x; i++){}
        if(i*i == x) return i;
        return i-1;
    }
};

// Approach 2: Time Complexity - O(LogN)
class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sq = 1LL * mid * mid;
            if(sq > x){
                high = mid - 1;
            }else if(sq == x){
                return mid;
            }else{
                low = mid + 1;
            }
        }
        return high;
    }
};
