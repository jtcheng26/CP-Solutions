#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct shft {
  ll s, t, b;
};

ll n;
shft cows[101];
ll milk[1001] = {0};

bool cmp(shft a, shft b) {
  return a.s < b.s;
}

ll solve() {
  sort(cows, cows + n, cmp);
  ll mx = 0;
  for (int i=0;i<n;i++) {
    for (int j=cows[i].s;j<=cows[i].t;j++) {
      milk[j] += cows[i].b;
      mx = max(mx, milk[j]);
    }
  }
  return mx;
}

int main() {
  ofstream fout ("blist.out");
  ifstream fin ("blist.in");
  fin >> n;
  for (int i=0;i<n;i++) {
    shft c;
    fin >> c.s >> c.t >> c.b;
    cows[i] = c;
  }
  fout << solve() << endl;
  return 0;
}
