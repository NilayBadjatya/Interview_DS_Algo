class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int currZ = 0, prev = 0, one = 0, maxOnes = 0, zeroSegment = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                currZ++;
            }else{
                one++;
                maxOnes = max(maxOnes, currZ + prev);
                if(currZ != 0){
                    prev = currZ;
                    zeroSegment++;
                }
                currZ = 0;
            }
        }
        if(currZ > 0){
            maxOnes = max(maxOnes, currZ + prev);
            if(currZ != 0){
                prev = currZ;
                zeroSegment++;
            }
        }
        if(zeroSegment < 2){
            return one;
        }
        return one + maxOnes;
    }
};
