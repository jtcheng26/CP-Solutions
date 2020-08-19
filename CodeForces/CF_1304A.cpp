#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int x, y, a, b;

ll solve() {
  if ((y - x) % (a + b) != 0) return -1;
  return (y - x) / (a + b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> x >> y >> a >> b;
    cout << solve() << endl;
  }

  return 0;
}
