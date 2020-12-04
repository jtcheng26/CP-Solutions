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

int d, k;

bool ok(int x, int y) {
  return ((ll)x) * ((ll)x) + ((ll)y) * ((ll)y) <= ((ll)d) * ((ll)d);
}

string solve() {
  string odd = "Ashish";
  string even = "Utkarsh";
  int x = 0;
  int y = k * (d / k);
  int maxDist = d / k;
  for (y;y>=0;y-=k) {
    do {
      x += k;
    } while (ok(x, y));
    x -= k;
    maxDist = max(maxDist, x / k + y / k);
  }
  if (maxDist % 2 == 0) return even;
  else return odd;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> d >> k;
    cout << solve() << "\n";
  }
  return 0;
}
