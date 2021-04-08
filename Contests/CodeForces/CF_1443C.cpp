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
int a[200001];
int b[200001];

bool valid(int time) {
  ll req = 0;
  for (int i=0;i<n;i++) {
    if (a[i] > time) {
      req += b[i];
    }
  }
  return req <= time;
}

int solve() {
  int l = 1;
  int r = 1000000001;
  int res = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (valid(mid)) {
      r = mid;
      res = mid;
    } else {
      l = mid+1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    for (int i=0;i<n;i++) {
      cin >> b[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}
