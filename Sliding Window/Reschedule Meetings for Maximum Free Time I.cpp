class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) {
        int n = s.size();
        vector<vector<int>> a(n, vector<int> (2));
        for(int i = 0; i < n; i++){
            a[i][0] = s[i];
            a[i][1] = e[i];
        }
        sort(a.begin(), a.end());
        int end = 0;
        vector<int> ft;
        for(int i = 0; i < n; i++){
            ft.push_back(a[i][0] - end);
            end = a[i][1];
        }
        ft.push_back(eventTime - end);
        int i = 0, j = 0, m = ft.size(), sum = 0, res = 0;
        while(j < m){
            sum += ft[j];
            if(j - i + 1 <= k){
                j++;
            }else if(j - i + 1 == k + 1){
                res = max(sum, res);
                sum -= ft[i];
                i++;
                j++;
            }
        }
        return res;
    }
};
