#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int a[1001];
int curr;

struct node {
  string stem;
  int leaf;
  vector<node*> children;
};

void dfs1(node* root) {
  int child_leaf = 0;
  while (curr < n) {
    if (a[curr] == child_leaf + 1) {
      node* child = new node;
      if (root->stem != "")
        child->stem = root->stem + "." + to_string(root->leaf);
      else if (root->leaf != 0)
        child->stem = to_string(root->leaf);
      else
        child->stem = "";
      child->leaf = child_leaf+1;
      child_leaf++;
      root->children.pb(child);
      curr++;
      dfs1(child);
    } else {
      return;
    }
  }
}

void dfs(vector<node>& v, node* root) {
  if (root->leaf != 0)
    v.pb(*root);
  for (node* child : root->children) {
    dfs(v, child);
  }
}

vector<node> solve() {
  vector<node> ans;
  curr = 0;
  node* root = new node;
  root->stem = "";
  root->leaf = 0;
  dfs1(root);
  // cout << root.children.size() << "\n";
  dfs(ans, root);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
    }
    vector<node> nodes = solve();
    for (node j : nodes) {
      if (j.stem != "")
        cout << (j.stem + "." + to_string(j.leaf)) << "\n";
      else
        cout << j.leaf << "\n";
    }
  }
  return 0;
}