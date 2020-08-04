/*
   LANG: C++14
   PROG: numtri
*/
/*
Works but too slow. See Numtri for better solution (r <= 1000)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

struct node {
  int val; int depth;
  node *left; node *right;
};

int r; int opt = 0;
vector<vector<node> > tree;

int dfs(node root, int total) {
  if (root.depth == r-1)
    return total;
  int l_res = dfs(*root.left, total+root.left->val);
  int r_res = dfs(*root.right, total+root.right->val);
  int res = max(l_res, r_res);
  if (res > opt)
    opt = res;
  return res;
}

int solve() {
  return dfs(tree[0][0], tree[0][0].val);
}

int main() {
  //ofstream fout ("numtri.out");
  //ifstream fin ("numtri.in");
  int n;
  cin >> r;//
  cin >> n;//
  if (r == 1) {
    cout << n << endl;
    return 0;
  }
  node root;
  root.val = n;
  vector<node> rootrow;
  rootrow.push_back(root);
  tree.push_back(rootrow);
  for (int i=1;i<r;i++) {
    vector<node> row;
    for (int j=0;j<i+1;j++) {
      cin >> n;//
      node ntri = {.val = n};
      row.push_back(ntri);
    }
    tree.push_back(row);
  }
  for (int i=0;i<tree.size();i++) {
    for (int j=0;j<tree[i].size();j++) {
      tree[i][j].depth = i;
      if (i < tree.size()-1) {
        node *pl = &tree[i+1][j];
        node *pr = &tree[i+1][j+1];
        tree[i][j].left = pl;
        tree[i][j].right = pr;
      }
      //cout << tree[i][j].val << tree[i][j].left->val << tree[i][j].right->val << endl;
    }
  }
  cout << solve() << endl;//
  return 0;
}
