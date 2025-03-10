//Time Complexity - O(NLogN)
class Solution {
public:

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int binarySearch(vector<int>& nextCon, int k, int m){
        int n = nextCon.size();
        int l = 0, r = n-1, idx = m;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nextCon[mid] > k){
                idx = nextCon[mid];
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return idx;
    }

    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int i = 0, j = 0, c = 0;
        long long ans = 0;
        unordered_map<char, int> mp;
        vector<int> nextCon;
        for(int i = 0; i < n; i++){
            if(!isVowel(word[i])){
                nextCon.push_back(i);
            }
        }
        while(j < n){
            if(isVowel(word[j])){
                mp[word[j]]++;
            }else{
                c++;
            }
            while(mp.size() >= 5 && c == k){
                int idx = binarySearch(nextCon, j, n);
                ans += (idx - j);
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]] == 0){
                        mp.erase(word[i]);
                    }
                }else{
                    c--;
                }
                i++;
            }
            while(c > k){
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]] == 0){
                        mp.erase(word[i]);
                    }
                }else{
                    c--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
