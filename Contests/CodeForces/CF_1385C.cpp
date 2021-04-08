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
int a[200002];

int solve() {
  int res = 0;
  a[0] = -1;
  a[n+1] = -1;
  int prev = a[n+1];
  int curr = a[n];
  for (int i=n;i>=1;i--) {
    if (a[i] != curr) {
      if (a[i] > curr && curr < prev) return i;
      prev = curr;
      curr = a[i];
    }
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
