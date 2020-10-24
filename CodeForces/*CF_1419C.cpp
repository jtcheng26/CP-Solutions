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

int n, x;
int a[1001];

int solve() {
  int res = 0;
  ll sum = 0;
  int infected = 0;
  for (int i=0;i<n;i++) if (a[i] == x) infected++;
  if (infected == n) return 0;
  if (infected > 0) return 1;
  for (int i=0;i<n;i++) sum += x - a[i];
  if (sum == 0) return 1;
  return 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
