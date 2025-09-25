class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> res;
        for(int i = 1; i <= n; i++){
            int maxBit = 0;
            for(int bit = 31; bit >= 0; bit--){
                if((i >> bit) & 1){
                    maxBit = bit;
                    break;
                }
            }
            string temp = "";
            for(int bit = maxBit; bit >= 0; bit--){
                if((i >> bit) & 1){
                    temp += '1';
                }else{
                    temp += '0';
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
