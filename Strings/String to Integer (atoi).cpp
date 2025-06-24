class Solution {
public:
    int myAtoi(string s) {

        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);

        int n = s.size();
        int negative = 1;
        int i = 0;
        string num = "";
        while (i < n) {
            if (isdigit(s[i]) == false) {
                if (s[i] == '-' && i == 0) {
                    negative = -1;
                    i++;
                    continue;
                } else if(s[i] == '+' && i == 0) {
                    i++;
                    continue;
                }else{
                    break;
                }
            }
            num += s[i];
            i++;
        }

        i = 0;
        while(num[i] == '0'){
            i++;
        }

        num = num.substr(i);
        int size = num.size();
        long long ans = 0;
        i = 0;

        while(size--){
            ans = (ans * 10) + (num[i] - '0');
            if(negative == 1 && ans > INT_MAX){
                return INT_MAX;
            }else if(negative == -1 && -ans < INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        
        return (negative * ans);
    }
};
