class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int sum = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int before = i + 1;
            int after = n - i;
            sum += (arr[i] * before * after);
        }
        return sum;
    }
};
