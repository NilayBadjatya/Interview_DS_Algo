class Solution {
  public:
  
    int helper(vector<int>& heights, vector<int>& cost, int mid){
        int sum = 0;
        for(int i = 0; i < cost.size(); i++){
            sum += abs(heights[i] - mid) * cost[i];
        }
        return sum;
    }
  
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int l = *min_element(heights.begin(), heights.end());
        int r = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int x = helper(heights, cost, mid);
            int y = helper(heights, cost, mid+1);
            if(x > y){
                l = mid + 1;
            }else{
                r = mid-1;
            }
            ans = min(ans, x);
        }
        
        return ans;
    }
};
