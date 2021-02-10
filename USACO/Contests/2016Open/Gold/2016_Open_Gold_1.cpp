#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct cow {
  ll x, y;
};

int n;
cow a[50001];

bool cmp(cow a, cow b) {
  return a.x < b.x;
}

void flipAll() {
  for (int i=0;i<n;i++) {
    int temp = a[i].x;
    a[i].x = a[i].y;
    a[i].y = temp;
  }
}

ll solve() {
  sort(a, a+n, cmp);
  ll res = 0;
  ll pfxMin[n];
  ll pfxMax[n];
  ll sfxMin[n];
  ll sfxMax[n];
  pfxMin[0] = a[0].y;
  pfxMax[0] = a[0].y;
  sfxMin[n-1] = a[n-1].y;
  sfxMax[n-1] = a[n-1].y;
  for (int i=1;i<n;i++) {
    pfxMin[i] = min(pfxMin[i-1], a[i].y);
    pfxMax[i] = max(pfxMax[i-1], a[i].y);
  }
  for (int i=n-2;i>=0;i--) {
    sfxMin[i] = min(sfxMin[i+1], a[i].y);
    sfxMax[i] = max(sfxMax[i+1], a[i].y);
  }
  ll one = (sfxMax[0] - sfxMin[0]) * (a[n-1].x - a[0].x);
  //cout << one << "\n";
  for (int i=0;i<n-1;i++) {
    if (a[i].x != a[i+1].x) {
      ll area1 = (a[i].x - a[0].x) * (pfxMax[i] - pfxMin[i]);
      ll area2 = (a[n-1].x - a[i+1].x) * (sfxMax[i+1] - sfxMin[i+1]);
      //cout << area1 << " " << area2 << "\n";
      res = max(res, one - (area1 + area2));
    }
  }
  return res;
}

int main() {
  ofstream cout ("split.out");
  ifstream cin ("split.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i].x >> a[i].y;
  }
  ll ans = solve();
  flipAll();
  ans = max(ans, solve());
  cout << ans << "\n";
  return 0;
}
