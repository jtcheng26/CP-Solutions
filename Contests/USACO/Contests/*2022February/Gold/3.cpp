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

int n;
ll dp[1 << 19];
int pref[19][19];
bool visited[19];
vector<int> adj[19];

bool in(int i, int bm) { return bm & (1 << --i); }

int with(int i, int bm) { return bm ^ (1 << --i); }

// ll go(int bm, int k) {
//   if (dp[bm][k] != -1) {
//     return dp[bm][k];
//   }
//   if (bm == 0) return 1;
//   dp[bm][k] = 0;
//   for (int i = 1; i <= n; i++) {
//     if (in(i, bm) && pref[i][k] >= pref[i][i]) {
//       int w = with(i, bm);
//       dp[bm][k] += go(w, i);
//     }
//   }
//   return dp[bm][k];
// }

ll dfs(int node, int bm) {

}

int q[100006];

ll dpc[1 << 19];

void solve() {
  // for (int j=1;j<=n;j++) {
  //   for (int k=1;k<=n;k++) {
  //     cout << pref[j][k] << " ";
  //   }
  //   cout << "\n";
  // }
  int N = (1 << n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i=1;i<=19;i++) {
    for (int j=1;j<=19;j++) {
      if (pref[i][j] >= pref[i][i]) {
        adj[i].pb(j);
      }
    }
  }
  for (int b=0;b<N;b++) {
    for (int i=0;i<=n;i++) {
      visited[i] = false;
    }
    for (int i=1;i<=n)
  }
}

void printBM(int mask) {
  cout << "\n";
  for (int i = 1; i <= n; i++) {
    cout << (in(i, mask) ? "1" : "0");
  }
  cout << "\n";
}

ll query(int mask) {
  return dpc[mask] * dpc[(~mask & ((1 << n) - 1))];
 }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int j = 1; j <= n; j++) {
    for (int i = n; i > 0; i--) {
      int k;
      cin >> k;
      pref[j][k] = i;
    }
  }
  solve();
  int qs;
  cin >> qs;
  for (int i = 0; i < qs; i++) {
    int qu = 0;
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'H')
        qu = with(j + 1, qu);
    }
    cout << query(qu) << "\n";
  }
  return 0;
}
