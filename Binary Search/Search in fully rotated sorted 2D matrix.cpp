// Approach 1 O(Log(N*M)):
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &arr, int x) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int size = m * n;
        int l = 0, r = size - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int row = mid / m;
            int col = mid % m;
            int lr = l / m;
            int lc = l % m;
            int rr = r / m;
            int rc = r % m;
            if(arr[row][col] == x) return true;
            if(arr[lr][lc] == arr[row][col] && arr[rr][rc] == arr[row][col]){
                l++;
                r--;
                continue;
            }
            if(arr[lr][lc] <= arr[row][col]){
                if(x >= arr[lr][lc] && x <= arr[row][col]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else if(arr[rr][rc] >= arr[row][col]){
                if(x >= arr[row][col] && x <= arr[rr][rc]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};

// Approach 2 : O(N*M)
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        vector<int> arr;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        int size = m * n;
        int l = 0, r = size - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] == x) return true;
            if(arr[l] == arr[mid] && arr[r] == arr[mid]){
                l++;
                r--;
                continue;
            }
            if(arr[l] <= arr[mid]){
                if(x >= arr[l] && x <= arr[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else if(arr[r] >= arr[mid]){
                if(x >= arr[mid] && x <= arr[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
