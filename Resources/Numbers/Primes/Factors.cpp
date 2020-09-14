/* Prime factorization!
*/

// unique prime factors, push back in while statements for full prime factorization
vector<int> primeFactors(int n) {
  vector<int> nums;
  if (n % 2 == 0) nums.pb(2);
  while (n % 2 == 0) {
    n = n/2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    if (n % i == 0) nums.pb(i);
    while (n % i == 0) {
      n = n/i;
    }
  }
  if (n > 2) nums.pb(n);
  return nums;
}

// alternative, find unique prime factors in O(logA) time with help of sieve of Eratosthenes
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
vector<int> primeFactors(int n) {
  vector<int> nums;
  int curr = n;
  while (curr != 1) {
    if (minPrime[curr] == 0) minPrime[curr] = curr;
    if (nums.empty() || nums[nums.size()-1] != minPrime[curr])
      nums.pb(minPrime[curr]);
    curr /= minPrime[curr];
  }
  return nums;
}
