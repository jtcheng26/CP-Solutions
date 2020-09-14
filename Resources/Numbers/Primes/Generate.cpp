/* Generate a list of primes up to a certain number!
*/

// Returns a vector of all prime numbers from 2 to limit.
vector<ll> make_primes(ll limit) {
  vector<ll> primes;
  for (int i=0;i<=limit; i++)
    primes.push_back(true);
  prime[0] = prime[1] = false;
  for (int i=2;i*i<=limit;i++){
    if (prime[i]){
      for (int k=limit/i,j=i*k;k>=i;k--,j-=i){
        if (prime[k])
          prime[j] = false;
      }
    }
  }
  return primes;
}

// finds the minimum prime factor of all numbers from 2 to limit.
void sieve() {
  int limit = 10000000;
  minPrime[0] = minPrime[1] = 1;
  for (int i=2;i*i<=limit;i++) {
    if (minPrime[i] == 0) {
      minPrime[i] = i;
      for (int j=i*i;j<=limit;j+=i) {
        if (minPrime[j] == 0) minPrime[j] = i;
        else minPrime[j] = min(minPrime[j], i);
      }
    }
  }
}
