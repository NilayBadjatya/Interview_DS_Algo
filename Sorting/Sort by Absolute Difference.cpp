class Solution {
  public:
  
    void merge(vector<int>& arr, int low, int mid, int high, int x){
        vector<int> temp;
        int i = low, j = mid+1;
        while(i <= mid && j <= high){
            int diffA = abs(x - arr[i]);
            int diffB = abs(x - arr[j]);
            if(diffA <= diffB){
                temp.push_back(arr[i++]);
            }else{
                temp.push_back(arr[j++]);
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        
        while(j <= high){
            temp.push_back(arr[j++]);
        }
        
        for(int i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
    }
  
    void mergeSort(vector<int>& arr, int low, int high, int x){
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, x);
        mergeSort(arr, mid+1, high, x);
        merge(arr, low, mid, high, x);
    }
  
    void rearrange(vector<int> &arr, int x) {
        // code here
        int n = arr.size();
        mergeSort(arr, 0, n-1, x);
    }
};
