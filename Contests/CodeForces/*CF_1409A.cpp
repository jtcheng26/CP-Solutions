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

ll a, b;

ll solve() {
  int res = 0;
  if (a == b) return 0;
  if (abs(a-b) <= 10) return 1;
  if (abs(a-b) <= 19) return 2;
  return abs(a - b) / 10 + !((a - b) % 10 == 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << solve() << endl;
  }
  return 0;
}
