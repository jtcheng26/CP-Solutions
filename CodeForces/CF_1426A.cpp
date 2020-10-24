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

int n, x;

int solve() {
  int res = 0;
  if (n == 1 && x == 1) return 1;
  return (n - 2 + x - 1) / x + 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    cout << solve() << endl;
  }
  return 0;
}
