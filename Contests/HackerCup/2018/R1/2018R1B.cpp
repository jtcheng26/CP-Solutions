#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int n, k;
int ans[10000];

struct tree {
  pair<int, int> nums[10001];
  int pre[10001]; int post[10001]; // nodes at locations
  int preloc[10001]; int postloc[10001]; // loc of nodes
  void init() {
    for (int i=0;i<10001;i++) {
      pair<int, int> p;
      nums[i] = p;
      nums[i].first = nums[i].second = 0;
    }
  }
  void set_children(int root, int left, int right) {
    nums[root].first = left;
    nums[root].second = right;
  }
  int pre_order(int ind, int node) {
    //cout << ind << " " << node << endl;
    if (node == 0 || ind > n) return ind - 1;
    //cout << "p " << endl;
    pre[ind] = node;
    preloc[node] = ind;
    ind = pre_order(++ind, nums[node].first);
    ind = pre_order(++ind, nums[node].second);
    return ind;
  }
  int* pre_order() {
    pre_order(1, 1);
    return pre;
  }
  int* pre_loc() {
    return preloc;
  }
  int post_order(int ind, int node) {
    //cout << ind << " " << node << endl;
    if (node == 0 || ind > n) return ind;
    //cout << "p " << endl;
    ind = post_order(ind, nums[node].first);
    ind = post_order(ind, nums[node].second);
    post[ind] = node;
    postloc[node] = ind;
    return ++ind;;
  }
  int* post_order() {
    post_order(1, 1);
    return post;
  }
  int* post_loc() {
    return postloc;
  }
};

tree bt;

void dfs(int* pre, int* post, int* preloc, int* postloc, int label, int ind) { // ind = indice of pre/post order
  //cout << pre[ind] << " " << post[ind] << " " << ind << endl;
  if (ans[pre[ind]] > - 1 && ans[post[ind]] > -1) return;
  //cout << "p" << endl;
  if (ans[pre[ind]] == -1) ans[pre[ind]] = label;
  if (ans[post[ind]] == -1) ans[post[ind]] = label;
  dfs(pre, post, preloc, postloc, label, postloc[pre[ind]]);
  dfs(pre, post, preloc, postloc, label, preloc[post[ind]]);
}

bool solve() {
  int res = 1;
  int* pre; int* post; int* preloc; int* postloc;
  pre = bt.pre_order();
  post = bt.post_order();
  preloc = bt.pre_loc();
  postloc = bt.post_loc();
  int label = 0;
  for (int i=1;i<=n;i++) {
    //cout << preloc[i] << " ";
    //ans[i] = pre[i];
    if (ans[pre[i]] == -1 || ans[post[i]] == -1) {
      if (label < k) label++;
      dfs(pre, post, preloc, postloc, label, i);
    }
  }
  //cout << endl;
  return label == k;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("ethan_traverses_a_tree_input.txt");
  ofstream cout ("2018R1B.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n >> k;
    bt.init();
    for (int j=1;j<=n;j++) {
      ans[j] = -1;
      int l, r;
      cin >> l >> r;
      bt.set_children(j, l, r);
    }
    cout << "Case #" << i << ": ";//
    if (!solve()) {
      cout << "Impossible" << endl;
      continue;
    }
    for (int j=1;j<n;j++) {
      cout << ans[j] << " ";
    }
    cout << ans[n] << endl;
  }
  return 0;
}
