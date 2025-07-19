class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), total = 0;
        unordered_set<int> st;
        for(auto& x : nums){
            if(x == k){
                x = -1;
                total++;
            }
            st.insert(x);
        }

        int max_freq = total;
        for(int i = 1; i <= 50; i++){
            if(st.count(i) == 0) continue;
            int temp = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    temp++;
                }else if(nums[j] == -1){
                    temp--;
                    if(temp < 0){
                        temp = 0;
                    }
                }
            max_freq = max(max_freq, total + temp);
            }
        }
        return max_freq;
    }
};
