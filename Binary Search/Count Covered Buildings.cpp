class Solution {
public:

    bool binarySearchSmaller(vector<int>& nums, int ele){
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] >= ele){
                r = mid - 1;
            }else if(nums[mid] < ele){
                return true;
            }
        }
        return false;
    }

    bool binarySearchGreater(vector<int>& nums, int ele){
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= ele){
                l = mid + 1;
            }else if(nums[mid] > ele){
                return true;
            }
        }
        return false;
    }

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int , vector<int>> rows, cols;
        for(auto& b : buildings){
            int x = b[0];
            int y = b[1];
            rows[x].push_back(y);
            cols[y].push_back(x);
        }
        for(auto& x : rows){
            sort(x.second.begin(), x.second.end());
        }
        for(auto& x : cols){
            sort(x.second.begin(), x.second.end());
        }
        int covered = 0;
        for(auto& b : buildings){
            int x = b[0];
            int y = b[1];
            bool left = false, right = false, upper = false, lower = false;
            left = binarySearchSmaller(rows[x], y);
            right = binarySearchGreater(rows[x], y);
            upper = binarySearchSmaller(cols[y], x);
            lower = binarySearchGreater(cols[y], x);
            if(left && right && upper && lower){
                covered++;
            }
        }
        return covered;
    }
};
