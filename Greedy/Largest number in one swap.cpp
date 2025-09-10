class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int n = s.size();
        vector<int> a(n);
        a[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            if(s[i] > s[a[i+1]]){
                a[i] = i;
            }else{
                a[i] = a[i+1];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(s[i] < s[a[i]]){
                swap(s[i], s[a[i]]);
                break;
            }
        }
        return s;
    }
};
