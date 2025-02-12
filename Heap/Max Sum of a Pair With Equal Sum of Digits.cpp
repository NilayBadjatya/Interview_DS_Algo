// O(nlog(n)) Approach
typedef priority_queue<int> P;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> digitSum(n);
        unordered_map<int, P> mp;
        for(int i = 0; i < n; i++){
            int m = nums[i], sum = 0;
            while(m > 0){
                int r = m % 10;
                sum += r;
                m = m / 10;
            }
            digitSum[i] = sum;
            mp[sum].push(nums[i]);
        }
        if(mp.size() == n){
            return -1;
        }
        int maxi = 0;
        for(auto &x : mp){
            if(x.second.size() >= 2){
                int f1 = x.second.top();
                x.second.pop();
                int f2 = x.second.top();
                maxi = max(maxi, f1+f2);
            }
        }
        return maxi;
    }
};
