class Solution {
public:

    bool isValid(int x, int num){
        if(num % x != 0){
            return false;
        }
        return true;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> t(n, 1);
        int res = 1, maxiIdx = 0;
        vector<int> answer;
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isValid(nums[j], nums[i])){
                    if(t[i] < t[j] + 1){
                        t[i] = t[j]+1;
                        parent[i] = j;
                    }
                    if(t[i] > res){
                        res = t[i];
                        maxiIdx = i;
                    }
                }
            }
        }
        int i = maxiIdx;
        while(i != -1){
            answer.push_back(nums[i]);
            i = parent[i];
        }
        return answer;
    }
};
