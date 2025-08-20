class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int dup = -1, miss = -1;
        for(int i = 0; i < n; i++){
            int ele = abs(arr[i]);
            if(arr[ele-1] > 0){
                arr[ele-1] = -arr[ele-1];
            }else{
                dup = ele;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] > 0){
                miss = i+1;
                break;
            }
        }
        
        return {dup, miss};
    }
};
