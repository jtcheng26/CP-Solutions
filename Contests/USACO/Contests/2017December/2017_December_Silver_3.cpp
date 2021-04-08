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
int component[100001];
int fnd = 0;
bool notFnd;

int dfs(int parent, int node, int comp) {
  //cout << node << "\n";
  component[node] = comp;
  for (int child : adj[node]) {
    if (child == node) return 1;
    if (component[child] == -1) {
      int len = dfs(node, child, comp);
      //cout << "len from " << child << ": " << len << "\n";
      if (len > 0) {
        if (node == fnd)
          notFnd = false;
        return len + notFnd;
       }
    } else if (component[child] == comp) {
      //cout << "fnd" << "\n";
      fnd = child;
      notFnd = true;
      return 2;
    }
  }
  return 0;
}

int solve() {
  int res = 0;
  for (int i=1;i<=n;i++) component[i] = -1;
  int c = 0;
  for (int i=1;i<=n;i++) {
    if (component[i] != -1) continue;
    res += dfs(0, i, ++c);
    //cout << "res: " << res << "\n";
  }
  return res;
}

int main() {
  ofstream cout ("shuffle.out");
  ifstream cin ("shuffle.in");
  cin >> n;
  for (int i=1;i<=n;i++) {
    int v;
    cin >> v;
    adj[i].pb(v);
  }
  cout << solve() << endl;
  return 0;
}
