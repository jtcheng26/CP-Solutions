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

int c, h, g;

double temp(ll n) {
  return g - ((n - n / 2) * h + (n / 2) * c) / ((double) n);
}

int solve() {
  int res = 2;
  int left = 0;
  int right = 1000000000;
  while (left < right) {
    int mid = (left + right) / 2;
    int odd = 1 + mid * 2;
    if (abs(temp(odd)) < abs(temp(res))) {
      res = odd;
    } else if (abs(temp(odd)) == abs(temp(res))) {
      res = min(res, odd);
    }
    if (temp(odd) < 0) {
      left = mid+1;
    } else {
      right = mid;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> h >> c >> g;
    cout << solve() << "\n";
  }
  return 0;
}
