#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, x, pos;
ll fact[1001];

void getFacts(int num) {
  fact[0] = 1;
  for (int i=1;i<=num;i++) {
    fact[i] = (i * fact[i-1]) % MOD;
  }
}

ll solve() {
  ll res = 0;
  getFacts(n);
  int left = 0;
  int right = n;
  int less = 0; // positions that must be less than x
  int greater = 0;
  while (left < right) {
    int mid = (left + right) / 2;
    //cout << mid << "\n";
    if (mid <= pos) {
      left = mid + 1;
      if (mid < pos) less++;
    } else {
      right = mid;
      greater++;
    }
  }
  //cout << less << " " << greater << "\n";
  ll l = x-1;
  for (int i=1;i<less;i++) {
    l = (l * (x - 1 - i)) % MOD;
  }
  ll g = n - x;
  for (int i=1;i<greater;i++) {
    g = (g * (n - x - i)) % MOD;
  }
  res = fact[n-(less+greater+1)];
  if (less > 0) {
    res *= l;
    res %= MOD;
  }
  if (greater > 0) {
    res *= g;
    res %= MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> x >> pos;
  cout << solve() << endl;
  return 0;
}
