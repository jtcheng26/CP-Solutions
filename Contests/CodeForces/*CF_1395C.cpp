#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

int n, m;
int a[202];
int b[202];

int solve() {
  for (int i=0;i<512;i++) {
    bool ok = true;
    for (int j=1;j<=n;j++) {
      ok = false;
      for (int k=1;k<=m;k++) {
        if (((a[j] & b[k]) | i) == i) {
          //cout << i << endl;
          ok = true;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) return i;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for (int j=1;j<=m;j++) {
    cin >> b[j];
  }
  cout << solve() << endl;
  return 0;
}
