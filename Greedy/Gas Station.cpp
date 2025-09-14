class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int n = gas.size(), total = 0, index = 0, fuel = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            total += diff;
            fuel += diff;
            if(fuel < 0){
                index = i+1;
                fuel = 0;
            }
        }
        return total >= 0 ? index : -1;
    }
};
