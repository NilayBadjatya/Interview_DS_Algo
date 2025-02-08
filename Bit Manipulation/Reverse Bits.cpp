//Approach 1: String Manipulation Method
typedef uint32_t u;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s = bitset<32>(n).to_string();
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        u x = bitset<32>(s).to_ulong();
        return x;
    }
};

//Approach 2: Using Bit Manipulation

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            res = (res << 1) | !((n & (1 << i)) == 0); // We can also use n >>= 1 instead of !((n & (1 << i)) == 0);
        }
        return res;
    }
};
