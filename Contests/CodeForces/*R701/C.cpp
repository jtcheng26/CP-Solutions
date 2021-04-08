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

int a, b;

ll solve() {
  ll res = 0;
  for (int i=1;i<=(int)sqrt(a);i++) {
    if (i >= b) break;
    res += max(0, min((a - i) / i - i, b - i));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << solve() << "\n";
  }
  return 0;
}
