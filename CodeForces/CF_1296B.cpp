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

typedef long long ll;

using namespace std;

int n;

int solve() {
  int res = n;
  while (n > 0) {
    if (n < 10) break;
    int spend = ((n / 10) * 10);
    n -= spend;
    n += spend / 10;
    res += spend / 10;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve() << endl;
  }
  return 0;
}
