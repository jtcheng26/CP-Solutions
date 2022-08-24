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

struct qu {
  char t;
  int a, b;
};

int n, q;
qu qs[200006];
vector<int> adj[200006];
int ans[200006];
bool good[200006];

void dfs(int node, int k) {
  ans[node] = k;
  good[node] = true;
  for (int child : adj[node]) {
    if (!good[child]) dfs(child, k);
  }
}

void solve() {
  vector<qu> added;
  vector<bool> rem(q+1, false);

  for (int i=1;i<=n;i++) {
    ans[i] = q;
    good[i] = true;
  }

  added.pb({'0', 0, 0 }); // for 1-indexing
  for (int i=1;i<=q;i++) {
    if (qs[i].t == 'A') added.pb(qs[i]);
    else if (qs[i].t == 'D') good[qs[i].a] = false;
    else rem[qs[i].a] = true;
  }

  for (int i=1;i<int(added.size());i++) {
    if (!rem[i]) {
      adj[added[i].a].pb(added[i].b);
      adj[added[i].b].pb(added[i].a);
    }
  }

  for (int i=1;i<=n;i++) {
    if (good[i]) dfs(i, q);
  }

  for (int i=q;i>=1;i--) {
    if (qs[i].t == 'R') {
      int a = added[qs[i].a].a;
      int b = added[qs[i].a].b;
      if (good[a] != good[b]) {
        if (!good[a]) {
          dfs(a, i-1);
        } else {
          dfs(b, i-1);
        }
      }
      adj[a].pb(b);
      adj[b].pb(a);
    } else if (qs[i].t == 'D') {
      if (!good[qs[i].a]) {
        dfs(qs[i].a, i-1);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i=1;i<=q;i++) {
    char t;
    int a, b = 0;
    cin >> t >> a;
    if (t == 'A') cin >> b;
    qs[i] = { t, a, b };
  }
  solve();
  for (int i=1;i<=n;i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
