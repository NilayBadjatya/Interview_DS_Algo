class Solution {
  public:
    string longestString(vector<string> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](string& a, string& b){
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() > b.size();
        });
        unordered_set<string> st;
        for(auto& s : arr){
            st.insert(s);
        }
        string s = "";
        for(int i = 0; i < n; i++){
            string t = "";
            bool flag = true;
            for(auto& ch : arr[i]){
                t += ch;
                if(st.count(t) == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return arr[i];
            }
        }
        return s;
    }
};
