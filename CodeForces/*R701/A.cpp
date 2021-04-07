#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 2000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int a, b;

int solve() {
  int res = INF;
  for (int i=0;i<=sqrt(a);i++) {
    int k = 0;
    int a1 = a;
    while (a1 != 0) {
      k++;
      int orig = a1;
      a1 = a1 / (b + i);
      if (a1 == orig) break;
    }
    if (b + i == 1) continue;
    if (a1 != 0) {
      k += 2;
    }
    res = min(res, k + i);
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
