vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) { // Optimised from i <= n to i*i <= n
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    // Collect all prime numbers
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            primes.push_back(i);
    }

    return primes;
}
Time Complexity - O(nloglogn).
