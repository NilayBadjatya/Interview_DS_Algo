class Solution {

    String findCommon(String a, String b){
        String res = "";
        int i = 0, j = 0;
        while(i < a.length() && j < b.length()){
            if(a.charAt(i) != b.charAt(i)){
                return res;
            }
            res += a.charAt(i);
            i++;
            j++;
        }
        return res;
    }

    public String longestCommonPrefix(String[] nums) {
        int n = nums.length;
        String res = nums[0];
        for(int i = 1; i < n; i++){
            res = findCommon(res, nums[i]);
        }
        return res;
    }
}

---------------------------C++-------------------------

  class Solution {
public:

    string findCommon(string& a, string& b){
        string res = "";
        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] != b[j]){
                return res;
            }
            res += a[i];
            i++;
            j++;
        }
        return res;
    }

    string longestCommonPrefix(vector<string>& nums) {
        int n = nums.size();
        string commonPrefix = nums[0];
        for(int i = 1; i < n; i++){
            commonPrefix = findCommon(commonPrefix, nums[i]);
            if(commonPrefix == ""){
                return "";
            }
        }
        return commonPrefix;
    }
};
