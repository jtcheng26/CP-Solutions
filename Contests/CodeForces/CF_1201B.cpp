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
int a[100001];

bool solve() {
  int mx = 0;
  ll cnt = 0;
  for (int i=0;i<n;i++) {
    mx = max(mx, a[i]);
    cnt += a[i];
  }
  if (cnt % 2 == 1) return false;
  if (mx > cnt - mx) return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << (solve() ? "YES" : "NO") << endl;
  return 0;
}
