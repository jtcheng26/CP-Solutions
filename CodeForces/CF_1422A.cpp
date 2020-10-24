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

int a[3];

int solve() {
  int res = 0;
  sort(a, a+3);
  return a[2];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a[0] >> a[1] >> a[2];
    cout << solve() << "\n";
  }
  return 0;
}
