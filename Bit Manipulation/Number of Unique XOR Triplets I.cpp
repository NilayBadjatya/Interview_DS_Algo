class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        if(n == 2) return 2;
        int evenPower = 2;
        for(int i = 3; i <= n; i++){
            int x = i;
            while(x % 2 == 0){
                x /= 2;
            }
            if(x == 1){
                evenPower = max(evenPower, i);
            }
        }
        int ans = (evenPower ^ (evenPower - 1)) + 1;
        return ans;
    }
};
