class Solution {
public:
    string pushDominoes(string d) {
        int m = d.size();
        vector<int> idx;
        d = 'L' + d;
        d += 'R';
        int n = d.size();
        string ans = d;
        for(int i = 0; i < n; i++){
            if(d[i] != '.'){
                idx.push_back(i);
            }
        }
        for(int i = 1; i < idx.size(); i++){
            char p = d[idx[i-1]];
            char n = d[idx[i]];
            if(p == 'R' && n == 'L'){
                int k = idx[i-1] + 1;
                int l = idx[i] - 1;
                while(k < l){
                    ans[k++] = 'R';
                    ans[l--] = 'L';
                }
            }else if(p == 'R' && n == 'R'){
                for(int j = idx[i-1]+1; j < idx[i]; j++){
                    ans[j] = 'R';
                }
            }else if(p == 'L' && n == 'L'){
                for(int j = idx[i]-1; j > idx[i-1]; j--){
                    ans[j] = 'L';
                }
            }
        }
        return ans.substr(1, m);
    }
};
