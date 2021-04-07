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

int n, k;

int solve() {
  if (n % 2 == 0 && k > n) return k % n == 0 ? n : k % n;
  else if (n % 2 == 0) return k;
  int res = (k % n + (k - 1) / (n / 2)) % n;
  if (res == 0) res = n;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << solve() << "\n";
  }
  return 0;
}
