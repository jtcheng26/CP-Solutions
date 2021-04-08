#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n[4];
int a[4][150001];
int m[4];
set<int> bad[3][150001];

int solve() {
  set<pair<int, int> > s[4];
  for (int i=0;i<n[0];i++) {
    s[0].insert(mp(a[0][i], i));
  }
  for (int i=1;i<4;i++) {
    for (int j=0;j<n[i];j++) {
      auto it = s[i-1].begin();
      while (it != s[i-1].end() && bad[i-1][j].count(it->S)) {
        it++;
      }
      if (it != s[i-1].end())
        s[i].insert(mp(it->F + a[i][j], j));
    }
    if (s[i].size() == 0) return -1;
  }
  return (s[3].begin() == s[3].end()) ? -1 : (s[3].begin()->F);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  for (int i=0;i<4;i++) cin >> n[i];
  for (int i=0;i<4;i++) {
    for (int j=0;j<n[i];j++) {
      cin >> a[i][j];
    }
  }
  for (int i=0;i<3;i++) {
    cin >> m[i];
    for (int j=0;j<m[i];j++) {
      int u, v;
      cin >> u >> v;
      bad[i][v-1].insert(u-1);
    }
  }
  cout << solve() << "\n";
  return 0;
}
