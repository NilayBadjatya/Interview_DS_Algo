class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        if(n == 1) return 0;
        unordered_map<int, int> mp, mp2;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                if(mat[i][j] == 1){
                    mp[i]++;
                    mp2[j]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mp[i] == 0 && mp2[i] == n-1) return i;
        }
        return -1;
    }
};
