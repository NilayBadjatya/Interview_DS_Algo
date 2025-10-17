class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows == 1){
            return s;
        }
        vector<vector<char>> arr(numRows, vector<char> (n, '#'));
        int i = 0, j = 0, k = 0;
        while(k < n){
            while(k < n && i < numRows){
                arr[i][j] = s[k++];
                i++;
            }
            i = numRows - 2, j++;
            while(k < n && i > 0){
                arr[i][j] = s[k++];
                i--;
                j++;
            }
        }

        /* for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        } */

        string res = "";
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] != '#'){
                    res += arr[i][j];
                }
            }
        }
        return res;
    }
};
