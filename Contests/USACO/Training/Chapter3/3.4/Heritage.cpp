/*
   LANG: C++11
   PROG: heritage
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
string pre;
string in;
string post;
vector<int> adj[27];
int passed[27] = {0};

string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void add_edge(int from, int to) {
  if (from == to) return;
  adj[from].pb(to);
  adj[to].pb(from);
}

// post-order
int dfs(int parent, int node, int index) {
  for (int i=0;i<adj[node].size();i++) {
    int child = adj[node][i];
    if (child == parent) continue;
    index = dfs(node, child, index);
  }
  post[index] = letters[node];
  return index + 1;
}

string solve() {
  int i = 0, j = 0; // i = pre-order position, j = in-order position
  int parent = pre[0] - 'A';
  post = "";
  for (int i=0;i<n;i++) post += " ";
  // construct tree
  while (i < n && j < n) {
    add_edge(parent, pre[i] - 'A');
    passed[pre[i] - 'A'] = true;
    parent = pre[i] - 'A';
    if (pre[i] == in[j]) {
      while (passed[in[j] - 'A']) {
        parent = in[j] - 'A';
        j++;
      }
    }
    i++;
  }
  dfs(-1, pre[0] - 'A', 0);
  return post;
}

int main() {
  ofstream cout ("heritage.out");
  ifstream cin ("heritage.in");
  cin >> in;
  cin >> pre;
  n = pre.length();
  cout << solve() << endl;
  return 0;
}
