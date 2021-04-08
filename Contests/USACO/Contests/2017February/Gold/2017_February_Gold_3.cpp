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
int l[100001];
int r[100001];

int solve() {
  int res = 0;
  BIT bit;
  bit.init(n);
  l[a[0]] = 0;
  for (int i=1;i<n;i++) {
    if (l[a[i]] == 0 && a[i] != a[0]) {
      l[a[i]] = i;
    } else {
      r[a[i]] = i;
    }
  }
  for (int i=0;i<n;i++) {
    if (i == l[a[i]]) {
      bit.add(i, 1);
    } else {
      bit.add(l[a[i]], -1);
      res += bit.sum(l[a[i]], i);
    }
  }
  return res;
}

int main() {
  ofstream cout ("circlecross.out");
  ifstream cin ("circlecross.in");
  cin >> n;
  n *= 2;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
