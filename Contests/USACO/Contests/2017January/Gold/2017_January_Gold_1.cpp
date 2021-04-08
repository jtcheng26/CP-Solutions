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
pair<int, int> a[100001];

int solve() {
  sort(a, a+n, greater<pair<int, int> >());
  BIT bit;
  bit.init(n);
  int res = 0;
  for (int i=0;i<n;i++) {
    int l = a[i].S-1 < 0 ? 0 : bit.sum(0, a[i].S-1);
    int r = a[i].S+1 > n - 1 ? 0 : bit.sum(a[i].S+1, n - 1);
    if (max(l, r) > 2 * min(l, r))
      res++;
    bit.add(a[i].S, 1);
  }
  return res;
}

int main() {
  ofstream cout ("bphoto.out");
  ifstream cin ("bphoto.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> a[i].F;
    a[i].S = i;
  }
  cout << solve() << endl;
  return 0;
}
