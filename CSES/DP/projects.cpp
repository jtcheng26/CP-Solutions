#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

struct project {
  int a, b, p;
};

int n;
project projects[200001];

bool cmp(project a, project b) {
  return a.b < b.b;
}

ll solve() {
  ll res = 0;
  ll dp[n];
  ll pfx[n];
  sort(projects, projects+n, cmp);
  for (int i=0;i<n;i++) {
    pfx[i] = 0;
  }
  for (int i=0;i<n;i++) {
    int l = 0;
    int r = i;
    while (l < r) {
      int mid = (l + r) / 2;
      if (projects[i].a > projects[mid].b) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    dp[i] = (l == 0 ? 0 : pfx[l-1]) + projects[i].p;
    if (i > 0)
      pfx[i] = max(pfx[i-1], dp[i]);
    else
      pfx[i] = dp[i];
    res = max(res, dp[i]);
  }
  return res;
}

int main() {
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> projects[i].a >> projects[i].b >> projects[i].p;
  }
  cout << solve() << endl;
  return 0;
}
