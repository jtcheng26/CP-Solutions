/*
   LANG: C++14
   PROG: numtri
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define RMAX 1000

typedef long long ll;

using namespace std;

struct node {
  int val;
  node *left; node *right;
};

int r; node root;
vector<vector<node> > dp;
// vector instead of array because initializing a 1000x1000 memory block is not allowed in the USACO grading system.

int dfs(int d) {
  int res = 0;
  if (d < 0) {
    return root.val + max(root.left->val, root.right->val);
  }
  else {
    for (int i=0;i<d+2;i++) {
      dp[d][i].val = dp[d][i].val + max(dp[d][i].left->val, dp[d][i].right->val);
    }
    res = dfs(--d);
  }
  return res;
}

int solve() {
  return dfs(r-3);
}

int main() {
  ofstream fout ("numtri.out");
  ifstream fin ("numtri.in");
  int n;
  fin >> r;//
  fin >> n;//
  if (r == 1) {
    fout << n << endl;//
    return 0;
  }
  root.val = n;
  for (int i=0;i<r-1;i++) {
    vector<node> row;
    for (int j=0;j<i+2;j++) {
      fin >> n;//
      node ntri = {.val = n};
      row.push_back(ntri);
    }
    dp.push_back(row);
  }
  node *pl = &dp[0][0];
  node *pr = &dp[0][1];
  root.left = pl;
  root.right = pr;
  for (int i=0;i<r-2;i++) {
    for (int j=0;j<i+2;j++) {
      if (i < r-2) {
        node *pl = &dp[i+1][j];
        node *pr = &dp[i+1][j+1];
        dp[i][j].left = pl;
        dp[i][j].right = pr;
      }
      //cout << dp[i][j].val << dp[i][j].left->val << dp[i][j].right->val << endl;
    }
  }
  fout << solve() << endl;//
  return 0;
}
