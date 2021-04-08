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

int a, b, n;

int solve() {
  int res = 0;
  if (b < a) swap(a, b);
  while (a <= n && b <= n) {
    a += b;
    if (b < a) swap(a, b);
    res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> n;
    cout << solve() << endl;
  }
  return 0;
}
