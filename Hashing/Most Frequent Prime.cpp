class Solution {
public:
    int m, n;

    bool isValid(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }

    void findAllNums(vector<vector<int>>& mat, int i, int j,
                     unordered_map<int, int>& mp, string s, int d1, int d2) {
        if (s.length() > 1) {
            int num = stoi(s);
            if (num > 10) {
                mp[num]++;
                // cout << num << " ";
            }
        }
        i += d1;
        j += d2;
        if (isValid(i, j)) {
            findAllNums(mat, i, j, mp, s + to_string(mat[i][j]), d1, d2);
        }
    }

    bool isPrime(int n) {
        if (n == 0 || n == 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        unordered_map<int, int> mp;
        vector<vector<int>> dir = {{1, 0},  {0, 1},  {-1, 0},  {0, -1},
                                   {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& v : dir) {
                    int x = i + v[0];
                    int y = j + v[1];
                    if (isValid(x, y)) {
                        findAllNums(mat, i, j, mp, to_string(mat[i][j]), v[0],
                                    v[1]);
                    }
                }
            }
        }
        vector<vector<int>> primes;
        for (auto& x : mp) {
            int num = x.first;
            int freq = x.second;
            if (isPrime(num)) {
                primes.push_back({freq, num});
            }
        }
        sort(primes.begin(), primes.end(), greater<vector<int>>());
        if (primes.size() == 0) {
            return -1;
        }
        return primes[0][1];
    }
};
