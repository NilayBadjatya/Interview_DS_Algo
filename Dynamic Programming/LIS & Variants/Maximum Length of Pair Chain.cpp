//C++ Code:-
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), res = 1;
        vector<int> t(n, 1);
        sort(pairs.begin(), pairs.end());
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = max(t[i], t[j]+1);
                    res = max(res, t[i]);
                }
            }
        }
        return res;
    }
};

//Java Code:- 
class Solution {
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length, res = 1;
        int[] t = new int[n];
        Arrays.fill(t, 1);
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[0], b[0]));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = Math.max(t[i], t[j]+1);
                    res = Math.max(res, t[i]);
                }
            }
        }
        return res;
    }
}
