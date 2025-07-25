class Solution {
public:

    void flip(vector<int>& arr, int k){
        int i = 0, j = k-1;
        while(i < j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    void solve(vector<int>& arr, int i, int j, vector<int>& ans){
        if(i == j){
            return;
        }
        int maxi = INT_MIN, maxi_idx = -1;
        for(int k = i; k <= j; k++){
            if(arr[k] > maxi){
                maxi = arr[k];
                maxi_idx = k;
            }
        }
        flip(arr, maxi_idx+1);
        flip(arr, j - i + 1);
        ans.push_back(maxi_idx+1);
        ans.push_back(j-i+1);
        return solve(arr, i, j-1, ans);
    }

    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        solve(arr, 0, n-1, ans);
        return ans;
    }
};
