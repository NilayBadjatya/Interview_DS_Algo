Time Complexity - O(Log(N))

ll binaryExpo(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll half = binaryExpo(a, b/2);
    ll result = (half * half) % MOD;
    if(b % 2 != 0){
        result = (result * a) % MOD;
    }
    return result;
}
