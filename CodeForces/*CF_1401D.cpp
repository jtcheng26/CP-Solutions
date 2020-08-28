#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define MOD 1000000007
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

ll n, m;
ll k[60001];
vector<int> adj[100001];
vector<ll> edge_w[100001];
bool visited[100001];

ll dfs(int node) {
  ll sub_cnt = 1;
  visited[node] = true;
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (visited[child]) continue;
    ll cnt = dfs(child);
    edge_w[node].pb((n - cnt) * cnt);
    //cout << node << " " << child << " " << edge_w[node][i] << endl;
    edge_w[child].pb((n - cnt) * cnt);
    sub_cnt += cnt;
  }
  return sub_cnt;
}

ll solve() {
  ll res = 0;
  dfs(1);
  priority_queue<ll> pq;
  for (int i=1;i<=n;i++) {
    for (int j=0;j<adj[i].size();j++) {
      pq.push(edge_w[i][j]);
    }
  }
  sort(k, k+m);
  vector<ll> ck;
  ck.pb(k[m-1]);
  int idx = m-2;
  while (m > n-1) {
    ck[0] = ck[0] * k[idx];
    ck[0] %= MOD;
    idx--;
    m--;
  }
  for (int i=idx;i>=0;i--) ck.pb(k[i]);
  //cout << "s " << pq.size() << endl;
  for (int i=0;i<ck.size();i++) {
    ll tp = pq.top();
    pq.pop();
    pq.pop(); // duplicates
    res += (tp * ck[i]) % MOD;
    res %= MOD;
  }
  //cout << "s" << pq.size() << endl;
  while (pq.size() > 0) {
    //cout << pq.size() << endl;
    ll tp = pq.top();
    pq.pop();
    pq.pop();
    res += tp;
    res %= MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<=n;i++) {
      adj[i].clear();
      edge_w[i].clear();
      visited[i] = false;
    }
    for (int i=0;i<n-1;i++) {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
    }
    cin >> m;
    for (int i=0;i<m;i++) {
      cin >> k[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
