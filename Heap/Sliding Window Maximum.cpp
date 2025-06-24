class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        unordered_map<int, int> mp;
        vector<int> res;
        int i = 0, j = 0;
        while(j < n){
            pq.push(nums[j]);
            mp[nums[j]]++;
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                while(mp[pq.top()] == 0){
                    pq.pop();
                }
                res.push_back(pq.top());
                mp[nums[i]]--;
                i++;
                j++;
            }
        }
        return res;
    }
};
