#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef unsigned long long ll;

using namespace std;

ll n;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll solve() {
  ll sum = 0;
  do {
    sum = 0;
    ll k = n;
    while (k > 0) {
      sum += k % 10;
      k /= 10;
    }
    n++;
  } while (gcd(n - 1, sum) <= 1);
  return n - 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
      cin >> n;
      cout << solve() << "\n";
  }
  return 0;
}