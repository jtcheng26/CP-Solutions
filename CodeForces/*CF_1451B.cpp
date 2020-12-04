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

int n, q;
char a[101];

bool solve(int l, int r) {
  for (int i=0;i<l;i++) {
    if (a[i] == a[l]) return true;
  }
  for (int i=r+1;i<n;i++) {
    if (a[i] == a[r]) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    for (int i=0;i<q;i++) {
      int l, r;
      cin >> l >> r;
      cout << (solve(l-1, r-1) ? "YES" : "NO") << "\n";
    }
  }
  return 0;
}
