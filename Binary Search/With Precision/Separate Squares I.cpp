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
                // ans = mid; Dont use ans variable instead directly submit l or r, dont know but gives error when using another variable to store value.
            }else if(upper > lower){ //Reason -> You only update ans when the areas are nearly equal, i.e., when abs(upper - lower) < 1e-5.
                                    //        But that condition may never happen exactly due to floating-point rounding or how square areas are distributed.
                                    // This is the only place where ans is updated. But if that abs(...) < 1e-5 condition never gets satisfied in the entire binary search loop, then ans remains -1.
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    }
};
