class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> a(n);
        a[0].push_back(1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    a[i].push_back(a[i-1][j]);
                }else if(j == i){
                    a[i].push_back(a[i-1][j-1]);
                }else{
                    a[i].push_back(a[i-1][j] + a[i-1][j-1]);
                }
            }
        }

        return a;
    }
};
