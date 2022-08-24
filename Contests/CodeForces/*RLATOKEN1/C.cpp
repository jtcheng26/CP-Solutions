#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[2][400001];
int c[400002];
int loc[2][400002];
int k = 0;

void dfs(int row, int col) {
  if (c[a[row][col]] == k) return;
  c[a[row][col]] = k;
  dfs(row, loc[row][a[!row][col]]);
}

ll solve() {
  for (int i=0;i<n;i++) {
    c[i+1] = 0;
    loc[0][a[0][i]] = i;
    loc[1][a[1][i]] = i;
  }
  k = 0;
  for (int i=0;i<n;i++) {
    if (c[a[0][i]] == 0) {
      k++;
      dfs(0, i);
    }
  }
  ll res = 1;
  for (int i=0;i<k;i++) {
    res = (2 * res) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int j=0;j<2;j++) {
      for (int i=0;i<n;i++) {
        cin >> a[j][i];
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}