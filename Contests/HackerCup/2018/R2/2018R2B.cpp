#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

/*
idea:
- get euler tour array from pre-order traversal of tree
- also store depth of each node
- store prices in euler tour order in segment tree
- store indexes as well
- on max query return pair w/ max price & index
- sort candy orders by subtree depth
- starting at lowest depth get max query on subtree
- if max query > -1, update index to -1
- add max value to answer
- else continue (skipped person)
- do this for all candy orders
- O(N + M Log N) (DFS is O(N), for each M query, segment tree updates are O(log N))
*/

int n, m;
vector<int> adj[2000001];
int cost[200001];
int price[2000001];
int pre[200001]; // pre order traversal
pair<int, int> rng[200001]; // range beg/end for subtrees (inclusive)
int depth[200001]; // depth of each node in tree
int candy[1000001];

struct SegTree {
  int sum;
  int n;
  vector<pair<int, int> > maxs;

  void init(int* prices, int rng_size) {
    int sz = 1;
    n = rng_size + 1;
    while (sz < n) sz *= 2;
    maxs.resize(sz * 2);
    build(prices, 0, 0, n);
  }

  // r is non-inclusive
  void build(int* prices, int index, int l, int r) {
    //cout << leftmost << " " << rightmost << endl;
    if (r - l == 1) {
      if (l < (ll) n) {
        maxs[index] = mp(prices[l], l);
      }
      return;
    }
    int mid = (l + r) / 2;
    int lchild = 2 * index + 1;
    int rchild = 2 * index + 2;
    build(prices, lchild, l, mid); // left child
    build(prices, rchild, mid, r); // right child
    maxs[index] = max(maxs[lchild], maxs[rchild]);
  }

  void ptUpdate(int rngIndex, int index, ll value, int l, int r) {
    if (rngIndex > r - 1 || rngIndex < l) return;
    if (r - l == 1) {
      maxs[index].F = value;
      return;
    }
    int mid = (l + r) / 2;
    ptUpdate(rngIndex, 2 * index + 1, value, l, mid);
    ptUpdate(rngIndex, 2 * index + 2, value, mid, r);
    maxs[index] = max(maxs[2 * index + 1], maxs[2 * index + 2]);
  }

  void ptUpdate(int index, ll value) {
    ptUpdate(index, 0, value, 0, n);
  }

  pair<int, int> maxQ(int rngl, int rngr, int index, int l, int r) {
    if (rngr < l || rngl >= r) return make_pair(-1, 0);
    if (rngr >= r - 1 && rngl <= l) {
      return maxs[index];
    }
    int mid = (l + r) / 2;
    pair<int, int> lmid = maxQ(rngl, rngr, 2 * index + 1, l, mid);
    pair<int, int> rmid = maxQ(rngl, rngr, 2 * index + 2, mid, r);
    return max(lmid, rmid);
  }

  pair<int, int> maxQ(int l, int r) {
    return maxQ(l, r, 0, 0, n);
  }

};

int dfs(int parent, int root, int index) {
  if (root >= n) return index - 1;
  pre[index] = root;
  int og = index;
  for (int i=0;i<adj[root].size();i++) {
    int child = adj[root][i];
    if (child == parent) continue;
    depth[child] = depth[root] + 1;
    index = dfs(root, child, ++index);
  }
  rng[root] = mp(og, index);
  return index;
}

bool cmp(int a, int b) {
  return depth[a] > depth[b];
}

ll solve() {
  ll res = 0;
  depth[0] = 0;
  dfs(-1, 0, 0);
  SegTree st;
  int* p = pre;
  st.init(p, n);
  sort(candy, candy + m, cmp);
  for (int i=0;i<m;i++) {
    pair<int, int> mx = st.maxQ(rng[candy[i]].F, rng[candy[i]].S);
    if (mx.F >= 0) res += mx.F;
    else continue;
    st.ptUpdate(mx.S, -1);
  }

  return res;
}

void gen(int a, int b) {
  for (int i=0;i<m;i++) {
    candy[i] = (a * i + b) % n;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("jacks_candy_shop_input.txt");
  ofstream cout ("2018R2B.txt");
  int t; int a, b;
  cin >> t;//
  for (int cse=1;cse<=t;cse++) {
    cin >> n >> m >> a >> b;
    price[0] = 0;
    for (int i=0;i<=n;i++) adj[i].clear();
    for (int i=1;i<=n-1;i++) {
      int u;
      cin >> u;
      adj[u].pb(i);
      adj[i].pb(u);
      price[i] = i;
    }
    gen(a, b);
    cout << "Case #" << cse << ": " << solve() << endl;//
  }
  return 0;
}
