#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <functional>

typedef long long ll;

using namespace std;

ll n = 0; ll s;
vector<vector<ll> > tree[100001]; // node, weight, paths
vector<pair<ll, ll> > edges; // weight, paths

class CompareDist {
  public:
      bool operator()(pair<ll,ll> n1,pair<ll,ll> n2) {
          return (n1.first - n1.first / 2) * n1.second < (n2.first - n2.first / 2) * n2.second;
      }
};

ll dfs(ll sum, int node, int ind, int parent) {
  if (node > 1) tree[parent][ind][2]++;
  //cout << node << " " << parent << endl;
  ll res = 0;
  if (tree[node].size() == 1 && node != 1) return sum;
  bool fnd = false;
  for (int i=0;i<tree[node].size();i++) {
    if (tree[node][i][0] != parent) {
      if (node > 1 && fnd) tree[parent][ind][2]++;
      fnd = true;
      //cout << node << " " << tree[node][i][1] << endl;
      res += dfs(sum + tree[node][i][1], tree[node][i][0], i, node);
      pair<ll, ll> e(tree[node][i][1], tree[node][i][2]);
      if (node > 1 && tree[node][i][2] > 1)
        tree[parent][ind][2] += tree[node][i][2] - 1;
      //cout << e.first << " " << e.second << endl;
      edges.push_back(e);
    }
  }
  //cout << res << endl;
  return res;
}

ll solve() {
  ll res = 0;
  ll sum = dfs(0, 1, 0, 0);
  for (int i=0;i<n-1;i++) {
    //cout << edges_w[i] << " " << edges_p[i] << endl;
  }
  if (sum <= s) return 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, CompareDist> pq;
  //function<bool(pair<ll,ll>, pair<ll, ll>)>
  for (int i=0;i<n-1;i++) {
    pq.push(edges[i]);
  }
  ll cnt = 0;
  while (sum > s) {
    //cout << sum << endl;
    //cout << pq.top().first << " " << pq.top().second << endl;
    cnt++;
    sum -= (pq.top().first - pq.top().first / 2) * pq.top().second;
    pair<ll, ll> f = pq.top();
    pq.pop();
    f.first /= 2;
    //cout << f.first << " " << f.second << endl;
    pq.push(f);
    //cout << pq.top().first << " " << pq.top().second << endl;
  }
  return cnt == 100000 ? 0 : cnt;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    for (int i=0;i<=n;i++) {
      tree[i].clear();
    }
    cin >> n >> s;
    edges.clear();
    for (int i=0;i<n-1;i++) {
      int a, b, c;
      cin >> a >> b >> c;
      vector<ll> l; vector<ll> l2;
      l.push_back(b);
      l.push_back(c);
      l.push_back(0);
      l2.push_back(a);
      l2.push_back(c);
      l2.push_back(0);
      //cout << a << " " << b << " " << c << endl;
      tree[a].push_back(l); tree[b].push_back(l2);
    }
    cout << solve() << endl;
  }

  return 0;
}
