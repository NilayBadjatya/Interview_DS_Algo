Approach 1 :- We process the number digit by digit from left to right, maintaining the remainder modulo 13 at each step using the formula:
rem = (rem * 10 + digit) % 13.

  class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem = 0;
        for(int i = 0; i < s.size(); i++){
            rem = (rem * 10 + (s[i] - '0')) % 13;
        }
        return rem == 0;
    }
};

Approach 2:- A number is divisible by 13 if and only if the alternating sum of its 3-digit blocks, taken from right to left, is divisible by 13. 
class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int n = s.size();
        string t = "";
        int first = 0, second = 0;
        for(int i = n-1; i >= 0; i--){
            t += s[i];
            if(t.size() == 3){
                swap(t[0], t[2]);
                if((i - 2) % 2 == 0){
                    first += stoi(t);
                }else{
                    second += stoi(t);
                }
                t = "";
            }
        }
        int idx = -1 + t.size();
        if((int)t.size() < 3 && t.size() > 0){
            reverse(t.begin(), t.end());
            if(idx % 2 == 0){
                first += stoi(t);
            }else{
                second += stoi(t);
            }
        }
        return (first - second) % 13 == 0;
    }
};
