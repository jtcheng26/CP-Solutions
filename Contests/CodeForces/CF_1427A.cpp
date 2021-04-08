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

bool cmp(int a, int b) {
  return a > b;
}

bool solve() {
  int sum = 0;
  for (int i=0;i<n;i++) sum += a[i];
  if (sum == 0) return false;
  else if (sum > 0) sort(a, a+n, cmp);
  else sort(a, a+n);
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    bool res = solve();
    if (res) {
      cout << "YES" << "\n";
      for (int i=0;i<n;i++) cout << a[i] << (i == n-1 ? "\n" : " ");
    } else cout << "NO" << "\n";
  }
  return 0;
}
