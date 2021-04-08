#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;

int solve() {
  int twos = 0;
  int fives = 0;
  const int primes[] = {2,5};
  for(int i = 0; i < 2; i++){
    ll cur = primes[i];
    ll total = 0;
    while(cur <= n){
      total += (n/cur);
      cur = cur*primes[i];
    }
    if (primes[i] == 2) twos = total;
    else if (primes[i] == 5) fives = total;
  }
  return min(twos, fives);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
