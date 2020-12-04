#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct query {
  int l, r, x;
};

int n, q;
query qs[100001];
int a[100001];

void solve() {
  vector<int> start[n];
  vector<int> end[n];
  for (int i=0;i<n;i++) {
    start[i].resize(0);
  }
  for (int i=0;i<q;i++) {
    start[qs[i].l].pb(i);
    end[qs[i].r].pb(i);
  }
  set<int> queries;
  for (int i=0;i<n;i++) {
    for (int j=0;j<start[i].size();j++) {
      queries.insert(start[i][j]);
    }
    if (queries.size() > 0) {
      if (a[i] > 0) {
        if (queries.size() % 2 == 0) {
          a[i] = qs[*prev(queries.end())].x;
        } else {
          a[i] = 0;
        }
      } else {
        if (queries.size() % 2 == 1) {
          a[i] = qs[*prev(queries.end())].x;
        }
      }
    }
    for (int j=0;j<end[i].size();j++) {
      queries.erase(queries.find(end[i][j]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> q;
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<q;i++) {
    cin >> qs[i].l >> qs[i].r >> qs[i].x;
    qs[i].l--;
    qs[i].r--;
  }
  solve();
  for (int i=0;i<n;i++) {
    cout << a[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
