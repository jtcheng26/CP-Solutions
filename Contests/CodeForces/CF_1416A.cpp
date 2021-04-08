#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[300001];
int k[300001];

int solve() {
  int res = 0;
  map<int, vector<int> > indices;
  for (int i=0;i<n;i++) {
    k[i] = 1000000007;
    if (indices[a[i]].size() == 2) {
      indices[a[i]][0] = max(indices[a[i]][0], i - indices[a[i]][1]);
      indices[a[i]][1] = i;
    } else {
      indices[a[i]].pb(i+1);
      indices[a[i]].pb(i);
    }
  }
  for (int i=0;i<n;i++) {
    indices[a[i]][0] = max(indices[a[i]][0], n - indices[a[i]][1]);
  }
  for (auto p : indices) {
    k[p.S[0]-1] = min(k[p.S[0]-1], p.F);
  }
  int mn = 1000000007;
  for (int i=1;i<=n;i++) {
    //cout << k[i-1] << endl;
    mn = min(mn, k[i-1]);
    if (mn == 1000000007) k[i-1] = -1;
    else k[i-1] = mn;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    solve();
    for (int i=0;i<n;i++) cout << k[i] << (i == n-1 ? "\n" : " ");
  }
  return 0;
}
