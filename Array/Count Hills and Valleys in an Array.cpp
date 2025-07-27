class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<int> a;
        for(auto& num : nums){
            if(a.empty() || num != a.back()){
                a.push_back(num);
            }
        }

        for(int i = 1; i < a.size()-1; i++){
            if(a[i] > a[i-1] && a[i] > a[i+1]){
                count++;
            }
            if(a[i] < a[i-1] && a[i] < a[i+1]){
                count++;
            }
        }
        return count;
    }
};
