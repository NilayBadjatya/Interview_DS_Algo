class Solution {

    public static boolean isValid(String haystack, String needle, int i){
        int n = haystack.length();
        int m = needle.length();

        int j = 0;
        while(i < n && j < m){
            if(haystack.charAt(i) != needle.charAt(j)){
                return false;
            }
            i++;
            j++;
        }
        return j == m;
    }

    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int m = needle.length();
        for(int i = 0; i < n; i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                if(isValid(haystack, needle, i)){
                    return i;
                }
            }
        }
        return -1;
    }
}



-------------------------C++--------------------------
class Solution {
public:

    bool isOccuring(string& haystack, string& needle, int i){
        int n = haystack.size();
        int m = needle.size();
        int j = 0;
        while(i < n && j < m){
            if(haystack[i] != needle[j]){
                return false;
            }
            i++;
            j++;
        }
        return j == m;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i < n; i++){
            if(haystack[i] == needle[0]){
                if(isOccuring(haystack, needle, i)){
                    return i;
                }
            }
        }
        return -1;
    }
};
