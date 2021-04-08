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
int a[51];

int solve() {
  int res = 0;
  bool flag = false;
  int l = 0;
  int r = 0;
  for (int i=0;i<n;i++) {
    if (a[i] == 1) {
      l = i;
      break;
    }
  }
  for (int i=n-1;i>=0;i--) {
    if (a[i] == 1) {
      r = i;
      break;
    }
  }
  for (l;l<r;l++) {
    if (a[l] == 0) res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << "\n";
  }
  return 0;
}
