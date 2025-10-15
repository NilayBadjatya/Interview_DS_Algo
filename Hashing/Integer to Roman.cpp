class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> arr;
        arr.push_back({"I", 1});
        arr.push_back({"IV", 4});
        arr.push_back({"V", 5});
        arr.push_back({"IX", 9});
        arr.push_back({"X", 10});
        arr.push_back({"XL", 40});
        arr.push_back({"L", 50});
        arr.push_back({"XC", 90});
        arr.push_back({"C", 100});
        arr.push_back({"CD", 400});
        arr.push_back({"D", 500});
        arr.push_back({"CM", 900});
        arr.push_back({"M", 1000});

        string res = "";
        
        while (num > 0) {
            for (int i = arr.size() - 1; i >= 0; i--) {
                if (arr[i].second <= num) {
                    res += arr[i].first;
                    num -= arr[i].second;
                    break;
                }
            }
        }
        return res;
    }
};
