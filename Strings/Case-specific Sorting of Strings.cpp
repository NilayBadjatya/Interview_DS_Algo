class Solution {
  public:
    string caseSort(string& s) {
        // code here
        int n = s.size();
        string upper = "", lower = "";
        
        for(int i = 0; i < n; i++){
            if(isupper(s[i])){
                upper.push_back(s[i]);
            }else{
                lower.push_back(s[i]);
            }
        }
        
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        
        int i = 0, j = 0, k = 0;
        string res = "";
        while(i < upper.size() && j < lower.size()){
            if(isupper(s[k])){
                res += upper[i++];
            }else{
                res += lower[j++];
            }
            k++;
        }
        
        while(i < upper.size()){
            res += upper[i++];
            k++;
        }
        
        while(j < lower.size()){
            res += lower[j++];
            k++;
        }
        
        return res;
    }
};
