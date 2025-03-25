class Solution {
public:

    int mergeInterval(vector<vector<int>>& nums){
        vector<int> temp = nums[0];
        vector<vector<int>> merged;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i][0] < temp[1]){
                temp[0] = min(temp[0], nums[i][0]);
                temp[1] = max(temp[1], nums[i][1]);
            }else{
                merged.push_back(temp);
                temp[0] = nums[i][0];
                temp[1] = nums[i][1];
            }
        }
        merged.push_back(temp);
        return (int)merged.size();
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> a, b;
        for(int i = 0; i < rectangles.size(); i++){
            a.push_back({rectangles[i][0], rectangles[i][2]});
            b.push_back({rectangles[i][1], rectangles[i][3]});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int x = mergeInterval(a);
        int y = mergeInterval(b);
        cout << x << " " << y;
        return x >= 3 || y >= 3;
    }
};
