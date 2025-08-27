class Solution {
  public:
  
    bool isValid(int x, int y, int z){
        return z+y > x;
    }
  
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            int j = 0, k = i-1;
            while(j < k){
                if(isValid(arr[i], arr[j], arr[k])){
                    ans += (k - j);
                    k--;
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};
