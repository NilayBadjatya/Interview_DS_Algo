class Solution {
  public:
  
    int find(vector<int>& b, int ele){
        int n = b.size();
        int l = 0, r = n-1, idx = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(b[mid] > ele){
                r = mid - 1;
            }else{
                idx = mid;
                l = mid + 1;
            }
        }
        return idx;
    }
  
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size(), m = b.size();
        sort(b.begin(), b.end());
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            int idx = find(b, a[i]);
            if(idx == -1) continue;
            ans[i] = (idx+1);
        }
        return ans;
    }
};
