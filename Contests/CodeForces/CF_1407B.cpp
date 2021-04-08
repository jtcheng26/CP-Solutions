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
int a[1001];
int b[1001];

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int solve() {
  int res = 0;
  bool used[1001] = {false};
  for (int i=1;i<n;i++) if (a[i] > a[res]) res = i;
  b[0] = a[res];
  used[res] = true;
  int c1 = a[res]; // prev gcd
  int c2 = 0; // highest found gcd
  for (int i=1;i<n;i++) {
    c2 = 0; int idx = 0;
    for (int j=0;j<n;j++) {
      if (used[j]) continue;
      int g = gcd(c1, a[j]);
      //cout << c1 << " " << a[j] << " " << g << endl;
      if (g > c2) {
        c2 = g;
        idx = j;
      }
    }
    used[idx] = true;
    b[i] = a[idx];
    c1 = c2;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<n;i++) cout << b[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
