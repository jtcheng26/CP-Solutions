// Time - 47:41

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct peak {
  ll x, y;
  ll l, r; //left, right base
};

ll n;
peak m[100001];
bool c[100001];

bool cmp(peak a, peak b) {
  return a.x < b.x;
}

bool covered(int m1, int m2) { // if mountain 1 covers mountain 2
  //cout << m[m1].x << " " << m[m1].y << " " << m[m2].x << " " << m[m2].y << endl;
  if (m[m2].y >= m[m1].y) return false; // m2 higher than m1
  if (m[m2].x >= m[m1].r || m[m2].x <= m[m1].l) return false; // m2 too far l/r of m1
  //cout << "t" << endl;
  if (abs(m[m1].x - m[m2].x) <= abs(m[m1].y - m[m2].y)) return true;
  return false;
}

int solve() {
  int res = n;
  for (int i=0;i<n;i++) c[i] = false;
  sort(m, m+n, cmp);
  for (int i=0;i<n;i++) {
    if (c[i]) continue;
    for (int j=i+1;j<n && m[j].x < m[i].r;j++) {
      if (!c[j] && covered(i, j)) {
        res--;
        c[j] = true;
      }
    }
    for (int j=i-1;j>=0 && m[j].x > m[i].l;j--) {
      if (!c[j] && covered(i, j)) {
        res--;
        c[j] = true;
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("mountains.out");
  ifstream cin ("mountains.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    peak p;
    cin >> p.x >> p.y;
    p.l = p.x - p.y;
    p.r = p.x + p.y;
    m[i] = p;
  }
  cout << solve() << endl;
  return 0;
}
