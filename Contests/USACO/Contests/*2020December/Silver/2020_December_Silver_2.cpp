#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct pt {
  int x, y;
};

int n;
pt pts[2501];

bool cmpx(pt a, pt b) {
  return a.x < b.x;
}

ll solve() {
  ll res = 1;
  sort(pts, pts+n, cmpx);
  int under[2501][2501]; // under first
  int over[2501][2501]; // over second
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      under[i][j] = 0;
      over[i][j] = 0;
    }
  }
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (pts[j].y < pts[i].y) {
        under[i][j]++;
      }
      under[i][j] += under[i][j-1];
    }
  }
  for (int i=n-1;i>=0;i--) {
    for (int j=i-1;j>=0;j--) {
      if (pts[j].y > pts[i].y) {
        over[j][i]++;
      }
      over[j][i] += over[j+1][i];
    }
  }
  for (int i=0;i<n;i++) {
    ll cnt = 1;
    for (int j=0;j<i;j++) {
      if (pts[j].y < pts[i].y) {
        cnt += (1 + under[j][i]) * (1 + over[j][i]);
      } else {
        cnt += (1 + i - j - under[j][i]) * (1 + i - j - over[j][i]);
      }
    }
    //cout << cnt << "\n";
    res += cnt;
  }
  return res;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  cout << solve() << endl;
  return 0;
}
