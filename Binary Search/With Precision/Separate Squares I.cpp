typedef pair<double, double> P;
class Solution {
public:
    P findArea(vector<vector<int>>& squares, double mid){
        double upper = 0, lower = 0;
        for(auto &v : squares){
            double x = v[0];
            double y = v[1];
            double l = v[2];
            if(y >= mid){
                upper += l*l;
            }else if(y+l <= mid){
                lower += l*l;
            }else{
                upper += l*(y+l-mid);
                lower += l*(mid - y);
            }
        }
        return {upper, lower};
    }
    double separateSquares(vector<vector<int>>& squares) {
        //Binary Search On Answer
        double l = INT_MAX, r = 0;
        for(auto &v : squares){
            l = min(l, (double)v[1]);
            r = max(r, (double)(v[1] + v[2]));
        }
        // double ans = 0;
        double eps = 1e-5;
        while(r - l > eps){
            double mid = l + (r - l) / 2.0;
            P area = findArea(squares, mid);
            double upper = area.first;
            double lower = area.second;
            if(abs(upper - lower) < eps){
                r = mid;
                // ans = mid; dont use this gives wrong result...instead directly submit l or r
            }else if(upper > lower){
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
