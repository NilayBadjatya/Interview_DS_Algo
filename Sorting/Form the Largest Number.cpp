class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> t;
        for(auto& x : arr){
            t.push_back(to_string(x));
        }
        sort(t.begin(), t.end(), [&](string& a, string& b){
            string s1 = "", s2 = "";
            s1 += a + b;
            s2 = b + a;
            if(s1 > s2) return false;
            return true;
        });
        string res = "";
        for(int i = n-1; i >= 0; i--){
            res += t[i];
        }
        if(res[0] == '0') return "0";
        return res;
    }
};
