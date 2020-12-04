/*
  Fast modular multiplicative inverse (for modular division).
*/

// modular multiplicative inverse 1, a bit slower
ll modInverse(ll n, ll p) {
  ll res = 1; ll y = p - 2;
   x = x % p;
   while (y > 0) {
     if (y & 1)
       res = (res * x) % p;
     y = y >> 1;
     x = (x * x) % p;
   }
   return res;
}

// a bit faster
int modInverse(int a, int m) {
  int x, y;
  int g = gcdExtended(a, m, &x, &y);
  if (g != 1)
    return -1;
  else {
    // m is added to handle negative x
    int res = (x%m + m) % m;
    return res;
  }
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0, *y = 1;  
    return b;
  }
  int x1, y1;
  int gcd = gcdExtended(b%a, a, &x1, &y1);
  *x = y1 - (b/a) * x1;
  *y = x1;
  return gcd;
}
