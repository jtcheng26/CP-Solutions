#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

ll n;
int a[100005];
vector<int> adj[100005];
ll ans[100005];
ll x;

void dfs(int root, ll d) {
  ans[root] = d * (n + 1) + x--;
  for (int i = adj[root].size() - 1; i >= 0; i--) {
    dfs(adj[root][i], d - 1);
  }
}

/*
    /7/  - 7 * 7 + 6 = 55
   /5/6 - 6 * 7 + 3, 6 * 7 + 5 = 45, 47
/-/3/4 - 5 * 7 + 2, 5 * 7 + 4 = 37, 39
1 2 - 4 * 7 + 0, 4 * 7 + 1 = 28, 29

*/

void solve() {
  x = n;
  for (int i = 1; i <= n; i++) {
    adj[a[i] + 1].pb(i);
  }
  dfs(n + 1, n + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  solve();
  cout << n + 1 << "\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
