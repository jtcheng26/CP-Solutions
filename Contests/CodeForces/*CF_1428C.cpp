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
string a;

int solve() {
  int res = a.length();
  int as = 0;
  int b = 0;
  for (int i=0;i<a.length();i++) {
    if (a[i] == 'A') as++;
    else {
      b++;
      if (as > 0) {
        as--;
        b--;
        res -= 2;
      }
    }
  }
  if (b % 2 == 0) res -= b;
  else res = res - b + 1;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> a;
    cout << solve() << endl;
  }
  return 0;
}
