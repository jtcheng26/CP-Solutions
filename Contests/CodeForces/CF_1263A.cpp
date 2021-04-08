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

int a, b, c;

int solve() {
  int res = 0;
  if (b > a) swap(a, b);
  if (c > a) swap(a, c);
  if (c > b) swap(b, c);
  if (a >= b + c) return b + c;
  return (a + b + c) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    cout << solve() << endl;
  }
  return 0;
}
