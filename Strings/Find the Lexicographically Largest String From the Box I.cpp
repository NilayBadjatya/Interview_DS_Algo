class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends == 1){
            return word;
        }
        vector<vector<int>> a(26);
        for(int i = 0; i < n; i++){
            a[word[i] - 'a'].push_back(i);
        }
        vector<int> largest;
        for(int i = 25; i >= 0; i--){
            if(a[i].size() > 0){
                largest = a[i];
                break;
            }
        }
        sort(largest.begin(), largest.end());
        string res = "";
        for(int i = 0; i < largest.size(); i++){
            int idx = largest[i];
            int before = idx, after = n - idx - 1;
            string temp = "";
            while(after + before + 1 >= numFriends && idx < n){
                temp += word[idx++];
                after--;
            }
            res = max(res, temp);
        }
        return res;
    }
};
