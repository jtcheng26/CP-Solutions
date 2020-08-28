#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int strength[300001];
vector<int> adj[300001];
vector<int> maxes; // banks that share a max strength
int max_strength = -1000000007;

int solve() {
  int res = max_strength;
  if (maxes.size() == 1) {
    int idx = 0;
    for (int i=1;i<=n;i++) {
      if (strength[i] == max_strength) idx = i;
      else strength[i] += 2;
    }
    for (int i=0;i<adj[idx].size();i++) {
      strength[adj[idx][i]]--;
    }
  } else { // check if there is some node that neighbors all max nodes
    for (int i=1;i<=n;i++) {
      if (adj[i].size() < maxes.size() - 1) continue;
      int cnt = strength[i] == max_strength ? 1 : 0;
      for (int j=0;j<adj[i].size();j++) {
        if (strength[adj[i][j]] == max_strength)
          cnt++;
      }
      if (cnt == maxes.size()) return res + 1;
    }
    return res + 2;
  }
  for (int i=1;i<=n;i++) {
    res = max(res, strength[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=1;i<=n;i++) {
    cin >> strength[i];
    if (strength[i] > max_strength) {
      max_strength = strength[i];
      maxes.clear();
      maxes.pb(i);
    } else if (strength[i] == max_strength)
        maxes.pb(i);
  }
  for (int i=0;i<n-1;i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  cout << solve() << endl;
  return 0;
}
