class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n % k != 0){
            return false;
        }
        if(k == 1){
            return true;
        }
        
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        for(auto& x : mp){
            int num = x.first;
            int count = x.second;
            while(count--){
                for(int i = 0; i < k; i++){
                    if(mp[num+i] == 0){
                        return false;
                    }
                    mp[num+i]--;
                }
            }
        }
        return true;
    }
};
