//Time Cpmplexity - O(N^2)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            bool isPlaced = false;
            for(int j = 0; j < n; j++){
                if(fruits[i] <= baskets[j] && st.count(j) == 0){
                    isPlaced = true;
                    st.insert(j);
                    break;
                }
            }
            if(!isPlaced){
                unplaced++;
            }
        }
        return unplaced;
    }
};
