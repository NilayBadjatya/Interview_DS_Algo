class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int, unordered_set<int>> tmp, bmp;
        for(int i = 0; i < n; i++){
            tmp[tops[i]].insert(i);
            bmp[bottoms[i]].insert(i);
        }   
        int ans = INT_MAX;
        //Checking top can become equal

        for(int i = 0; i <= 6; i++){
            int f1 = tmp[i].size();
            int f2 = 0;
            for(auto& x : bmp[i]){
                if(tmp[i].count(x) == 0){
                    f2++;
                }
            }
            if(f1 + f2 >= n){
                ans = min(ans, n - f1);
            }
        }

        //Checking bottoms can become equal

        for(int i = 0; i <= 6; i++){
            int f1 = bmp[i].size();
            int f2 = 0;
            for(auto& x : tmp[i]){
                if(bmp[i].count(x) == 0){
                    f2++;
                }
            }
            if(f1 + f2 >= n){
                ans = min(ans, n - f1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
