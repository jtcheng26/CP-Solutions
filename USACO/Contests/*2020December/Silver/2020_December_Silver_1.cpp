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
vector<int> adj[100001];

ll dfs(int parent, int node) {
  ll time = 0;
  int cnt = 1;
  int subtrees = adj[node].size() - 1;
  if (parent == 0)
    subtrees = adj[node].size();
  while (cnt <= subtrees) {
    cnt *= 2;
    time++;
  }
  for (int child : adj[node]) {
    if (child == parent) continue;
    time += 1 + dfs(node, child);
  }
  return time;
}

ll solve() {
  return dfs(0, 1);
}

int main() {
  cin >> n;
  for (int i=0;i<n-1;i++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  cout << solve() << endl;
  return 0;
}
