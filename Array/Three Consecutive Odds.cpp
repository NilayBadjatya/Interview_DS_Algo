class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = 2;
        while(j < n){
            if(arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[j] % 2 != 0){
                return true;
            }
            i++;
            j++;
        }
        return false;
    }
};
