//Time Complexity - O(N)
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++){
            colors.push_back(colors[i]);
        }
        int i = 0, j = 0, groups = 0, dupCount = 0;
        while(i < n){
            if(j > 0 && colors[j] == colors[j-1]){
                dupCount++;
            }
            if(j - i + 1 < k){
                j++;
            }else if(j - i + 1 == k){
                if(dupCount == 0){
                    groups++;
                }
                if(colors[i] == colors[i+1]){
                    dupCount--;
                }
                i++;
                j++;
            }
        }
        return groups;
    }
};
