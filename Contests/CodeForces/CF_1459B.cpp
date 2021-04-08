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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

int n;

int solve() {
  int res = 0;
  int sz = (2 * ((n + 1) / 2) + 1);
  if (n % 2 == 1) return (sz * sz) / 2;
  for (int i=1;i<=sz;i+=2) {
    int s = (i - 1) / 2;
    if ((n / 2) % 2 == s % 2) {
      res += i > 1 ? 2 * i - 2 : 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << "\n";
  return 0;
}
