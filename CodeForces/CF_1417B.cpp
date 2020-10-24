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

int n, bad;
int a[100001];
int color[100001];

int solve() {
  int res = 0;
  int curr = 0;
  for (int i=0;i<n;i++) {
    if (bad % 2 == 0 && a[i] == bad / 2) {
      color[i] = curr;
      curr = !curr;
    }
    else if (a[i] > bad / 2) color[i] = 1;
    else if (a[i] <= bad / 2) color[i] = 0;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> bad;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<n;i++) cout << color[i] << (i == n-1 ? "\n": " ");
  }
  return 0;
}
