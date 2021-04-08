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

int n, k;
ll m;
int cow[100001];
vector<int> cycle[100001];
int cycleOf[100001];
int idx[100001];
pair<int, int> swaps[200001];
vector<int> swapPos[2][100001];

void dfs(int node) {
  //cout << node << "\n";
  if (cycleOf[cow[node]] != -1) {
    cycleOf[node] = cycleOf[cow[node]];
    //cycle[cycleOf[cow[node]]].pb(cow[node]);
    cycle[cycleOf[cow[node]]].pb(node);
  } else {
    dfs(cow[node]);
    cycleOf[node] = cycleOf[cow[node]];
    cycle[cycleOf[cow[node]]].pb(node);
  }
  idx[node] = cycle[cycleOf[node]].size() - 1;
}

vector<int> solve() {
  //for (int i=1;i<=n;i++) cout << cow[i] << " ";
  //cout << "\n";
  vector<int> res(n, 0);
  vector<int> visited(n+1, 0);
  for (int i=1;i<=n;i++) {
    //cout << cow[i] << " ";
    cycleOf[i] = -1;
  }
  //cout << "\n";
  int cy = 0;
  for (int i=1;i<=n;i++) {
    if (cycleOf[i] == -1) {
      cycleOf[i] = cy++;
      dfs(i);
    }
  }
  for (int i=1;i<=n;i++) cow[i] = i;
  for (int i=0;i<k;i++) {
    int u = cow[swaps[i].F];
    int v = cow[swaps[i].S];
    int c = i >= (m % k);
    swapPos[c][u].pb(swaps[i].S);
    swapPos[c][v].pb(swaps[i].F);
    int temp = cow[swaps[i].F];
    cow[swaps[i].F] = cow[swaps[i].S];
    cow[swaps[i].S] = temp;
  }
  for (int i=1;i<=n;i++) {
    if (!visited[i]) {
      int loc = idx[i];
      int c = cycleOf[i];
      multiset<int> s;
      int cnt = 0;
      ll mod = cycle[c].size();
      for (int j=0;j<min(mod+1, m / k + 1);j++) {
        int u = cycle[c][(loc + j) % mod];
        if (s.find(u) == s.end()) cnt++;
        s.insert(u);
        for (int pos : swapPos[0][u]) {
          if (s.find(pos) == s.end()) cnt++;
          s.insert(pos);
        }
        if (j < m / k) {
          for (int pos : swapPos[1][u]) {
            if (s.find(pos) == s.end()) cnt++;
            s.insert(pos);
          }
        }
      }
      res[i-1] = cnt;
      visited[i] = true;
      int l = loc;
      int r = l + min(mod, m / k);
      r %= mod;
      do {
        int rl = cycle[c][l];
        int rr = cycle[c][r];
        for (int pos : swapPos[1][rr]) {
          if (s.find(pos) == s.end()) cnt++;
          s.insert(pos);
        }
        r = (r + 1) % mod;
        rr = cycle[c][r];
        if (s.find(rr) == s.end()) cnt++;
        s.insert(rr);
        for (int pos : swapPos[0][rr]) {
          if (s.find(pos) == s.end()) cnt++;
          s.insert(pos);
        }
        for (int pos : swapPos[0][rl]) {
          s.erase(s.find(pos));
          if (s.find(pos) == s.end()) cnt--;
        }
        for (int pos : swapPos[1][rl]) {
          s.erase(s.find(pos));
          if (s.find(pos) == s.end()) cnt--;
        }
        s.erase(s.find(rl));
        if (s.find(rl) == s.end()) cnt--;
        l = (l + 1) % mod;
        res[cycle[c][l]-1] = cnt;
        visited[cycle[c][l]] = true;
      } while (l != (idx[i]-1+mod)%mod);

    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k >> m;
  for (int i=1;i<=n;i++) cow[i] = i;
  for (int i=0;i<k;i++) {
    int u, v;
    cin >> u >> v;
    swaps[i] = mp(u, v);
    int temp = cow[u];
    cow[u] = cow[v];
    cow[v] = temp;
  }
  //for (int i=1;i<=n;i++) cow[c[i]] = i;
  vector<int> ans = solve();
  for (int i : ans) {
    cout << i << "\n";
  }
  return 0;
}
