// User function Template for C++

class Solution {
  public:
  
    vector<int> minPartition(int n) {
        // code here
        vector<int> c = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        
        while(n > 0){
            auto it = upper_bound(c.begin(), c.end(), n);
            if(it == c.begin()){
                break;
            }
            it--;
            n -= *it;
            ans.push_back(*it);
        }
        
        return ans;
    }
};
