class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int order = 0;
        vector<int> ans;
        for(int j = 0; j < n; j++){
            int i = 0, col = j;
            vector<int> temp;
            while(i < m && col >= 0){
                temp.push_back(mat[i][col]);
                i++;
                col--;
            }
            // cout << "Hello from first loop" << endl;
            if(order % 2 == 0){
                for(int k = temp.size()-1; k >= 0; k--){
                    ans.push_back(temp[k]);
                }
            }else{
                for(int k = 0; k < temp.size(); k++){
                    ans.push_back(temp[k]);
                }
            }
            order++;
        }

        for(int i = 1; i < m; i++){
            int j = n-1, row = i;
            vector<int> temp;
            while(row < m && j >= 0){
                temp.push_back(mat[row][j]);
                row++;
                j--;
            }
            // cout << "Hello from second loop" << endl;
            if(order % 2 == 0){
                for(int k = temp.size()-1; k >= 0; k--){
                    ans.push_back(temp[k]);
                }
            }else{
                for(int k = 0; k < temp.size(); k++){
                    ans.push_back(temp[k]);
                }
            }
            order++;
        }
        return ans;
    }
};
