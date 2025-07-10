class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<vector<int>> nums;
        for(int i = 0; i < n; i++){
            nums.push_back({startTime[i], endTime[i]});
        }
        sort(nums.begin(), nums.end());
        vector<int> freeTime;
        int prev = 0;
        for(int i = 0; i < n; i++){
            freeTime.push_back(nums[i][0] - prev);
            prev = nums[i][1];
        }
        freeTime.push_back(eventTime - prev);
        vector<int> prefix(n+1), suffix(n+1);
        prefix[0] = 0;
        suffix[n] = 0;
        for(int i = 1; i < n+1; i++){
            prefix[i] = max(prefix[i-1], freeTime[i-1]);
        }
        for(int i = n-1; i >= 0; i--){
            suffix[i] = max(suffix[i+1], freeTime[i+1]);
        }
        int maxGap = INT_MIN;
        for(int i = 1; i < n+1; i++){
            int len = nums[i-1][1] - nums[i-1][0];
            int maxi = max(prefix[i-1], suffix[i]);
            if(maxi >= len){
                maxGap = max(maxGap, freeTime[i-1]+freeTime[i]+len);
            }
            maxGap = max(maxGap, freeTime[i-1]+freeTime[i]);
        }
        return maxGap;
    }
};
