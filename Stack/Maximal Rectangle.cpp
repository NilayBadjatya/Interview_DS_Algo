class Solution {
public:
    vector<int> NSR(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nsr(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsr[i] = st.top();
            } else {
                nsr[i] = n;
            }
            st.push(i);
        }
        return nsr;
    }

    vector<int> NSL(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nsl(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsl[i] = st.top();
            } else {
                nsl[i] = -1;
            }
            st.push(i);
        }
        return nsl;
    }

    int histogram(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr = NSR(heights);
        vector<int> nsl = NSL(heights);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            area = max(area, (nsr[i] - nsl[i] - 1) * heights[i]);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> heights(n, 0);

        int area = INT_MIN;
        for (auto& row : grid) {
            for (int i = 0; i < n; i++) {
                if (row[i] == '1') {
                    heights[i]++;
                } else {
                    heights[i] = 0;
                }
            }
            area = max(area, histogram(heights));
        }
        return area;
    }
};
