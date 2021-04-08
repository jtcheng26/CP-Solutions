#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[100002];

int query(int i) {
  if (i < 1 || i > n) return INF;
  if (a[i] != -1) return a[i];
  int res;
  cout << "? " << i << endl;
  cin >> res;
  a[i] = res;
  return a[i];
}

void solve() {
  for (int i=0;i<=n+1;i++) {
    a[i] = -1;
  }
  if (query(2) > query(1)) {
    cout << "! 1" << endl;
    return;
  }
  if (n >= 2) {
    if (query(n-1) > query(n)) {
      cout << "! " << n << endl;
      return;
    }
  }
  int l = 1;
  int r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (query(mid) < query(mid-1) && query(mid) < query(mid+1)) {
      cout << "! " << mid << endl;
      return;
    }
    if (query(mid) == 1) {
      cout << "! " << mid << endl;
      return;
    }
    if (query(mid-1) == 1) {
      cout << "! " << mid-1 << endl;
      return;
    }
    if (query(mid+1) == 1) {
      cout << "! " << mid+1 << endl;
      return;
    }
    if (query(mid) > query(mid-1)) {
      r = mid-1;
    } else {
      l = mid;
    }
  }
}
//9 7 5 6 2 1 3 4 8

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  solve();
  return 0;
}
