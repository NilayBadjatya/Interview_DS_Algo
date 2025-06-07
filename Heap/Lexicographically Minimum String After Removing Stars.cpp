typedef pair<char, int> P;

struct CustomCompare {
    bool operator()(const P& a, const P& b) const {
        if (a.first == b.first)
            return a.second < b.second; // higher index is preferred
        return a.first > b.first; // smaller char is preferred
    }
};

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<P, vector<P>, CustomCompare> pq;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                s[i] = '#';
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '#';
            } else {
                pq.push({s[i], i});
            }
        }

        string res;
        for (char ch : s) {
            if (ch != '#') res += ch;
        }
        return res;
    }
};
