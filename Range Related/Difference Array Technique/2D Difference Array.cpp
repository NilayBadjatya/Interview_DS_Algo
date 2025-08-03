class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> diff(n, vector<int> (m, 0));
        
        for(auto& q : opr){
            int r1 = q[1];
            int c1 = q[2];
            int r2 = q[3];
            int c2 = q[4];
            int val = q[0];
            diff[r1][c1] += val;
            if(c2+1 < m) diff[r1][c2+1] -= val;
            if(r2+1 < n) diff[r2+1][c1] -= val;
            if(r2+1 < n && c2 + 1 < m) diff[r2+1][c2+1] += val;
        }
        for(int i = 0; i < n; i++){
                for(int j = 1; j < m; j++){
                    diff[i][j] += diff[i][j-1];
                }
            }
            for(int j = 0; j < m; j++){
                for(int i = 1; i < n; i++){
                    diff[i][j] += diff[i-1][j];
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    mat[i][j] += diff[i][j];
                }
            }
            return mat;
    }
};
