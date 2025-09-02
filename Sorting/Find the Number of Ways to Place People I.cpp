class Solution {
public:
    bool isUpperLeft(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0] && a[1] >= b[1];
    }

    bool checkRectangle(vector<vector<int>>& points, int a, int b) {
        int n = points.size();
        for (int i = 0; i < n; i++) {
            if (i == a || i == b)
                continue;
            if (points[i][0] >= points[a][0] && points[i][0] <= points[b][0] &&
                points[i][1] <= points[a][1] && points[i][1] >= points[b][1]) {
                return false;
            }
        }
        return true;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isUpperLeft(points[i], points[j])) {
                    if (checkRectangle(points, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
