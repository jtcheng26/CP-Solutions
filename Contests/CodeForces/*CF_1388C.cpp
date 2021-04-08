#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> lPair;

ll n, m;
ll pop[100010];
ll hap[100010];
ll passed[100010];
ll pos_i[100010];
vector<ll> children[100010];
bool res = true;

void dfs(ll u, ll p) {
  passed[u] = pop[u];
  ll pos_sum = 0;
  for (ll i=0;i<children[u].size();i++) {
    ll next_child = children[u][i];
    if (next_child == p) continue;
    dfs(next_child, u);
    pos_sum += pos_i[next_child];
    passed[u] += passed[next_child];
  }
  if ((passed[u] + hap[u]) % 2 != 0) res = false;
  pos_i[u] = (passed[u] + hap[u]) / 2;
  if (pos_i[u] < 0 || pos_i[u] > passed[u]) res = false;
  if (pos_sum > pos_i[u]) res = false;
}

void solve() {
  dfs(1, -1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ll t;
  cin >> t;
  for (ll i=0;i<t;i++) {
    cin >> n >> m;
    for (ll j=1;j<=n;j++) {
      cin >> pop[j];
    }
    for (ll j=1;j<=n;j++) {
      cin >> hap[j];
    }
    for (ll j=0;j<n-1;j++) {
      ll c1, c2;
      cin >> c1 >> c2;
      children[c1].push_back(c2);
      children[c2].push_back(c1);
    }
    solve();
    string ans = res ? "YES" : "NO";
    cout << ans << endl;
    res = true;
    for (int i=1;i<=n;i++) children[i].clear();
  }
  return 0;
}
