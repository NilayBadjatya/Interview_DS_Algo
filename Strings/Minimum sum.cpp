class Solution {
  public:
    string minSum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        string s1 = "", s2 = "";
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                s1 += (arr[i] + '0');
            else
                s2 += (arr[i] + '0');
        }

        string result = addStrings(s1, s2);
        int pos = 0;
        while(pos < result.size() - 1 && result[pos] == '0') pos++;
        return result.substr(pos);
    }

    string addStrings(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        int carry = 0, i = n - 1, j = m - 1;
        string res = "";
        while(i >= 0 && j >= 0){
            int x = (num1[i] - '0'), y = (num2[j] - '0');
            int sum = x + y + carry;
            if(sum > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            string t = to_string(sum);
            if(t.size() == 2){
                res += t[1];
            }else{
                res += t[0];
            }
            i--;
            j--;
        }
        
        while(i >= 0){
            int sum = carry + (num1[i] - '0');
            if(sum > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            string t = to_string(sum);
            if(t.size() == 2){
                res += t[1];
            }else{
                res += t[0];
            }
            i--; 
        }
        
        while(j >= 0){
            int sum = carry + (num2[j] - '0');
            if(sum > 9){
                carry = 1;
            }else{
                carry = 0;
            }
            string t = to_string(sum);
            if(t.size() == 2){
                res += t[1];
            }else{
                res += t[0];
            }
            j--; 
        }
        
        if(carry == 1){
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
