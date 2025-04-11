//C++ Code
class Solution {
public:

    bool isValid(string& s){
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += (s[i] - '0');
        }
        int half = s.size() / 2, x1 = 0;
        for(int i = 0; i < half; i++){
            x1 += (s[i] - '0');
        }
        int x2 = sum - x1;
        return x1 == x2;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            string s = to_string(i);
            if(s.size() % 2 == 0){
                if(isValid(s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//Java Code
class Solution {

    private boolean isValid(String s){
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            sum += (s.charAt(i) - '0');
        }
        int half = s.length() / 2, x1 = 0;
        for(int i = 0; i < half; i++){
            x1 += (s.charAt(i) - '0');
        }
        int x2 = sum - x1;
        return x1 == x2;
    }

    public int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            String s = Integer.toString(i);
            if(s.length() % 2 == 0){
                if(isValid(s)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
}
