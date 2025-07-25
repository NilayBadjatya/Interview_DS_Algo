class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort(pizzas.begin(), pizzas.end());
        int day = n / 4;
        int even = day / 2;
        int odd = day - even;
        long long sum = 0;
        int i = n-1;
        while(odd--){
            sum += pizzas[i];
            i--;
        }
        i--;

        while(even--){
            sum += pizzas[i];
            i -= 2;
        }
        return sum;
    }
};
