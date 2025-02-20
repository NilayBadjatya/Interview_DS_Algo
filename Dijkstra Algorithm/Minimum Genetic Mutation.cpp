typedef pair<int, string> P;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<char> dict = {'A', 'C', 'G', 'T'};
        unordered_set<string> visited;
        pq.push({0, startGene});
        while(!pq.empty()){
            string gene = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(gene == endGene){
                return dis;
            }
            for(int i = 0; i < 8; i++){
                char temp = gene[i];
                for(auto &ch : dict){
                    if(gene[i] == ch) continue;
                    gene[i] = ch;
                    if(st.count(gene) != 0 && visited.count(gene) == 0){
                        pq.push({dis + 1, gene});
                        visited.insert(gene);
                    }
                }
                gene[i] = temp;
            }
        }
        return -1;
    }
};
