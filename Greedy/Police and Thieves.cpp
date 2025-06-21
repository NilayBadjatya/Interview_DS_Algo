class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), ans = 0;
        
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++){
            if(arr[i] == 'P'){
                p[i] = 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(arr[i] == 'T'){
                bool f = false;
                for(int j = max(0, i-k); j < i; j++){
                    if(arr[j] == 'P' && p[j]){
                        ans++;
                        p[j] = 0;
                        arr[i] = '#';
                        f = true;
                        break;
                    }
                }
                if(f) continue;
                for(int j = i+1; j <= min(n-1, i+k); j++){
                    if(arr[j] == 'P' && p[j]){
                        ans++;
                        p[j] = 0;
                        arr[i] = '#';
                        break;
                    }
                }
            }
        }
        
        
        return ans;
    }
};
