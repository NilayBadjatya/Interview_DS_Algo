class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> ones, zero;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                ones.push_back(i);
            } else {
                zero.push_back(i);
            }
        }

        int even = ones.size();
        int odd = zero.size();
        if(abs(even - odd) > 1){
            return -1;
        }

        int ans1 = INT_MIN, ans2 = INT_MIN;
        if(even >= odd){
            int j = 0, moves = 0;
            for(int i = 0; i < n; i += 2){
                if(nums[i] % 2 == 0) continue;
                while(ones[j] % 2 == 0){
                    j++;
                }
                moves += abs(ones[j++] - i);
            }
            ans1 = max(ans1, moves);
        }

        if(odd >= even){
            int j = 0, moves = 0;
            for(int i = 0; i < n; i += 2){
                if(nums[i] % 2 != 0) continue;
                while(zero[j] % 2 == 0){
                    j++;
                }
                moves += abs(zero[j++] - i);
            }
            ans2 = max(ans2, moves);
        }

        if(ans1 == INT_MIN){
            return ans2;
        }else if(ans2 == INT_MIN){
            return ans1;
        }
        return min(ans1, ans2);
    }
};
