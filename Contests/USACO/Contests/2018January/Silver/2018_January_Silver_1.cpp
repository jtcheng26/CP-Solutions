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

struct pt {
  int t, idx, r;
};

int n;
pair<int, int> a[100001];

bool cmp(pt a, pt b) {
  return a.t < b.t;
}

int solve() {
  vector<pt> pts;
  for (int i=0;i<n;i++) {
    pt p1, p2;
    p1.t = a[i].F;
    p1.idx = p2.idx = i;
    p1.r = false;
    p2.t = a[i].S;
    p2.r = true;
    pts.pb(p1);
    pts.pb(p2);
  }
  sort(pts.begin(), pts.end(), cmp);
  int cnt = 0;
  int start = 0;
  int s = 0;
  for (pt p : pts) {
    if (!p.r) { // left endpoint
      if (cnt == 0) {
        cnt = 1;
        start = p.t;
      } else {
        cnt++;
      }
    } else {
      cnt--;
      if (cnt == 0) {
        s += p.t - start;
      }
    }
  }
  int res = INF;
  sort(a, a+n);
  int r = 0;
  for (int i=0;i<n;i++) {
    if (a[i].S < r) {
      res = 0;
    } else {
      r = max(r, a[i].S);
    }
  }
  for (pt p : pts) {
    if (!p.r) { // left endpoint
      if (cnt == 0) {
        cnt = 1;
        start = p.t;
      } else if (cnt == 1) {
        res = min(res, p.t - start);
        cnt++;
      } else {
        cnt++;
      }
    } else {
      cnt--;
      if (cnt == 1) {
        start = p.t;
      } else if (cnt == 0) {
        res = min(res, p.t - start);
      }
    }
  }
  return s - res;
}

int main() {
  ofstream cout ("lifeguards.out");
  ifstream cin ("lifeguards.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i].F >> a[i].S;
  }
  cout << solve() << endl;
  return 0;
}
