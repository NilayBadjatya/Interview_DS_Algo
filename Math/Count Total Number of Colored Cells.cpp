//Approach 1: Iterative O(N)
typedef long long ll;
class Solution {
public:
    long long coloredCells(int n) {
        vector<ll> a(n+2);
        a[1] = 1;
        a[2] = 5;
        for(int i = 3; i <= n; i++){
            a[i] = a[i-1] + 4 + (i-2) * 4;
        }
        return a[n];
    }
};

//Approach 2: Math O(1)
class Solution {
public:
    long long coloredCells(int n) {
        long long x = n;
        return 1 + 2 * (x-1) * (x);
    }
};
