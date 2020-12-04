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
int a[30001];

bool solve() {
  int res[n];
  int sub = 0;
  res[n-1] = a[n-1];
  for (int i=n-2;i>=0;i--) {
    res[i] = min(res[i+1], a[i] - sub);
    sub = a[i] - res[i];
    if (res[i] < 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
