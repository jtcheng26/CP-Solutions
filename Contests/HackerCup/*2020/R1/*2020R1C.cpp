#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, k;
vector<int> adj[1000009];
string s;
vector<int> comps;
vector<int> compsz;
pair<int, int> subrange[1000009];
vector<int> pre;
vector<int> e;
vector<int> rngc;
vector<int> rngcnt;
vector<int> zcnt;

int dfs(int c, int idx) {
  int sz = 1;
  if (adj[idx].size() == 0) return 1;
  comps[idx] = c;
  for (int i=0;i<adj[idx].size();i++) {
    if (s[adj[idx][i] - 1] == s[idx - 1] && comps[adj[idx][i]] == -1)
      sz += dfs(c, adj[idx][i]);
  }
  return sz;
}

void ff() {
  int c = 0;
  for (int i=0;i<=n;i++) {
    comps[i] = -1;
    compsz[i] = -1;
  }
  compsz[0] = 0;
  for (int i=1;i<=n;i++) {
    if (comps[i] == -1 && s[i-1] == '*') {
      c++;
      compsz[c] = dfs(c, i);
    } else if (comps[i] == -1)
      dfs(0, i);
  }
  //for (int i=0;i<n;i++)
    //cout << comps[i] << " " << compsz[comps[i]] << endl;
}

int pre_order(int ind, int parent, int node) {
  //cout << node << endl;
  //cout << ind << " " << node << endl;
  if (ind > n) return ind - 1;
  //cout << "p " << endl;
  pre[ind] = node;
  subrange[node].F = ind;
  for (int i=0;i<adj[node].size();i++) {
    //cout << node << " " << adj[node][i] << endl;
    if (adj[node][i] != parent)
      ind = pre_order(++ind, node, adj[node][i]);
  }
  subrange[node].S = ind;
  return ind;
}

//largest comp in subtree
int dfs2(int curr, int en) {
  //cout << "d2" << endl;
  //cout << pre[curr] << " " << rngc[pre[curr]] << endl;
  if (curr > en) return 0;
  if (rngc[pre[curr]] != -1) return rngc[pre[curr]];
  int node = pre[curr];
  rngc[node] = compsz[comps[node]];
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (rngc[child] == -1)
      rngc[node] = max(rngc[node], dfs2(subrange[child].F, subrange[child].S));
  }
  //cout << node << " " << rngc[node] << endl;
  return rngc[node];
}

// # of nodes of largest comp in subtree
int dfs3(int curr, int en, int mx) {
  if (curr > en) return 0;
  if (rngcnt[pre[curr]] != -1) return rngcnt[pre[curr]];
  int node = pre[curr];
  rngcnt[node] = (compsz[comps[node]] == mx) ? 1 : 0;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (rngcnt[child] == -1 && rngc[child] == rngc[node])
      rngcnt[node] += dfs3(subrange[child].F, subrange[child].S, mx);
    else if (rngc[child] != rngc[node])
      dfs3(subrange[child].F, subrange[child].S, rngc[child]);
  }
  return rngcnt[node];
}

// # of nodes in comp 0 in subtrees (for if total components <= 1)
int dfs4(int curr, int en) {
  //cout << "d" << endl;
  if (curr > en) return 0;
  if (zcnt[pre[curr]] != -1) return zcnt[pre[curr]];
  int node = pre[curr];
  zcnt[node] = comps[node] == 0 ? 1 : 0;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (zcnt[child] == -1)
      zcnt[node] += dfs4(subrange[child].F, subrange[child].S);
  }
  return zcnt[node];
}

pair<ll, ll> solve() {
  ll pairs = 0;
  //ll add = 0;
  ll total = 0;
  ll cmax = 0;
  int cnt = 0;
  int nz = 0;
  ff();
  pre_order(1, 0, 1);
  for (int i=1;i<=n;i++) {
    if (comps[i] == 0) nz++;
    rngc[i] = rngcnt[i] = zcnt[i] = -1;
    //cout << compsz[i] << endl;
    if (compsz[i] > -1) {
      pairs += (compsz[i] * (compsz[i] - 1)) / 2;
      cnt++;
    }
  }
  //cout << " initial " << pairs << endl;
  //cout << pairs << endl;
  int pfxc[n+1]; int sfxc[n+1];
  int pfxcnt[n+1]; int sfxcnt[n+1];
  pfxc[1] = compsz[comps[pre[1]]];
  sfxc[n] = compsz[comps[pre[n]]];
  pfxcnt[1] = 1;
  sfxcnt[n] = 1;
  for (int i=2;i<=n;i++) {
    int new_sz = compsz[comps[pre[i]]];
    if (new_sz > pfxc[i-1]) {
      pfxc[i] = new_sz;
      pfxcnt[i] = 1;
    } else {
      pfxc[i] = pfxc[i-1];
      pfxcnt[i] = pfxcnt[i-1];
      if (new_sz == pfxc[i-1]) pfxcnt[i]++;
    }
  }
  for (int i=n-1;i>=1;i--) {
    int new_sz = compsz[comps[pre[i]]];
    if (new_sz > sfxc[i+1]) {
      sfxc[i] = new_sz;
      sfxcnt[i] = 1;
    } else {
      sfxc[i] = sfxc[i+1];
      sfxcnt[i] = sfxcnt[i+1];
      if (new_sz == sfxc[i+1]) sfxcnt[i]++;
    }
  }
  pfxc[0] = pfxcnt[0] = sfxc[n+1] = sfxcnt[n+1] = 0;
  for (int i=1;i<=n;i++) {
    int st = subrange[i].F;
    int en = subrange[i].S;
    if (rngc[i] == -1) {
      dfs2(st, en);
      dfs3(st, en, rngc[i]);
      dfs4(st, en);
    }
  }
  // main loop
  for (int i=2;i<=n;i++) {
    if (cnt > 1 && s[i-1] == '*' && s[e[i]-1] == '*') continue;
    ll m1 = rngc[i]; ll q1 = rngcnt[i];
    ll outsidep, outsides;
    ll q2;
    outsidep = pfxc[subrange[i].F - 1];
    outsides = sfxc[subrange[i].S + 1];
    if (outsidep > outsides) {
      q2 = pfxcnt[subrange[i].F - 1];
    } else if (outsidep < outsides) {
      q2 = sfxcnt[subrange[i].S + 1];
    } else {
      q2 = sfxcnt[subrange[i].S + 1] + pfxcnt[subrange[i].F - 1];
    }
    ll m2 = max(outsidep, outsides);
    if (cnt <= 1) {
      int subsz = (subrange[i].S - subrange[i].F + 1);
      int cnt2 = 0; // infected in subtree
      int cnt3 = 0; // infected in rest of tree
      if (s[i-1] == '*' && s[e[i]-1] == '*') {
        cnt2 = zcnt[i];
        cnt3 = nz - cnt2;
      }
      //cout << "sz " << subsz << endl;
      //cout << cnt2 << " " << cnt3 << endl;
      total += (subsz - cnt2) * (n - cnt3 - subsz);
      continue;
    }
    if (m1 * m2 < cmax) continue;
    else if (m1 * m2 > cmax) {
      cmax = m1 * m2;
      total = 0;
    }
    total += q1 * q2;
  }
  if (cnt <= 1) cmax = 0;
  pair<ll, ll> res(pairs + cmax, total);
  return res;
}

void gen(ll a, ll b, ll c) {
  for (int i=k+2;i<=n;i++) {
    int ei = ((a * e[i-2] + b*e[i-1] + c) % (i-1)) + 1;
    adj[i].pb(ei);
    adj[ei].pb(i);
    e[i] = ei;
  }
  //cout << "gen" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("quarantine_input.txt");
  ofstream cout ("2020R1C.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    int a, b, c;
    cin >> n >> k;
    cin >> s;
    pre.resize(n+1);
    e.resize(n+1);
    rngc.resize(n+1);
    rngcnt.resize(n+1);
    zcnt.resize(n+1);
    compsz.resize(n+1);
    comps.resize(n+1);
    for (int i=2;i<=k+1;i++) {
      cin >> e[i];
      adj[i].pb(e[i]);
      adj[e[i]].pb(i);
    }
    cin >> a >> b >> c;
    gen(a, b, c);
    pair<ll, ll> ans = solve();
    cout << "Case #" << i << ": " << ans.F << " " << ans.S << endl;//
    for (int i=0;i<=n;i++) {
      adj[i].clear();
    }
    compsz.clear();
    pre.clear();
    e.clear();
    rngc.clear();
    rngcnt.clear();
    zcnt.clear();
    comps.clear();
  }
  return 0;
}
