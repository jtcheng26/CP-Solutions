/* Primality tests!
*/

// Returns whether or not a number is prime.
bool isPrime(ll n) {
  if (n <= 3)
    return n > 1;
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i=5;i*i<=n;i+=6) {
    if (n % i == 0 || n % (i+2) == 0)
      return false;
  }
  return true;
}
