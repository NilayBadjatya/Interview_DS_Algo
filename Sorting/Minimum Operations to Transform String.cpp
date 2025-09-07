class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(), s.end());
        int n = s.size();
        int i = 0, j = n-1;
        char first = '.', last = '.';
        while(i < n && s[i] == 'a'){
            i++;
        }
        if(i < n){
            first = s[i];
        }
        while(j >= 0 && s[j] == 'a'){
            j--;
        }
        if(j >= 0){
            last = s[j];
        }

        if(first == '.' && last == '.') return 0;
        int ops = last - first;
        ops += 26 - (last - 'a');
        return ops;
    }
};
