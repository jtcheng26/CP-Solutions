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
int a[300001];
int mx;

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {

    if (a[i] == a[mx]) {
      if (i > 0 && a[i] > a[i-1])
        return i + 1;
      if (i < n-1 && a[i] > a[i+1])
        return i+1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    mx = 0;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      if (a[i] > a[mx]) {
        mx = i;
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}
