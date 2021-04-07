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

struct BIT {
  vector<int> bit;
  void init(int n) {
    bit.assign(n, 0);
  }
  int sum(int r) {
    int res = 0;
    for (; r >= 0;r = (r & (r + 1)) - 1)
      res += bit[r];
    return res;
  }
  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
  void add(int idx, int d) {
    for (; idx < bit.size(); idx = idx | (idx + 1))
      bit[idx] += d;
  }
};

int n;
int a[100001];

int solve() {
  int res = 1;
  BIT bit;
  bit.init(n);
  vector<int> b;
  for (int i=0;i<n;i++) b.pb(a[i]);
  sort(b.begin(), b.end());
  map<int, int> c;
  for (int i=0;i<n;i++) {
    c[b[i]] = i;
  }
  for (int i=0;i<n;i++) {
    bit.add(c[a[i]], 1);
    res = max(res, i + 1 - bit.sum(0, i));
  }
  return res;
}

int main() {
  ofstream cout ("sort.out");
  ifstream cin ("sort.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << "\n";
  return 0;
}
