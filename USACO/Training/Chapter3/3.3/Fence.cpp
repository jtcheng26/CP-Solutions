/*
   LANG: C++11
   PROG: fence
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

int f;
vector<int> adj[1030];
vector<int> ans;
vector<int> poss;
vector<int> v;
int deleted[1025][1025];

bool cmp() {
  if (poss.size() != ans.size()) return poss.size() < ans.size();
  for (int i=0;i<ans.size();i++) {
    if (ans[i] != poss[poss.size() - 1 - i])
      return ans[i] > poss[poss.size() - 1 - i];
  }
  return false;
}

void find_circuit(int node) {
  for (int i=0;i<adj[node].size();i++) {
    int u = adj[node][i];
    if (deleted[node][u] <= 0) continue;
    deleted[node][u]--;
    deleted[u][node]--;
    find_circuit(u);
  }
  poss.push_back(node);
}

int solve() {
  sort(v.begin(), v.end());
  for (int i=0;i<v.size();i++) {
    sort(adj[v[i]].begin(), adj[v[i]].end());
  }
  int sz;
  for (sz=0;sz<v.size();sz++) {
    if (adj[v[sz]].size() % 2 == 1) break;
  }
  if (sz == v.size()) {
    for (sz=0;sz<v.size();sz++)
      if (adj[v[sz]].size() % 2 == 0) break;
  }
  //cout << sz << endl;
  poss.clear();
  for (int j=0;j<v.size();j++) {
    for (int k=0;k<adj[v[j]].size();k++) {
      deleted[v[j]][adj[v[j]][k]] = 0;
    }
  }
  for (int j=0;j<v.size();j++) {
    for (int k=0;k<adj[v[j]].size();k++) {
      deleted[v[j]][adj[v[j]][k]]++;
    }
  }
  find_circuit(v[sz]);
  //cout << poss.size() << endl;
  for (int j=poss.size()-1;j>=0;j--) {
    ans.push_back(poss[j]);
  }
  return 0;
}

int main() {
  ofstream cout ("fence.out");
  ifstream cin ("fence.in");
  cin >> f;
  for (int i=0;i<f;i++) {
    int a, b;
    cin >> a >> b;
    if (find(v.begin(), v.end(), a) == v.end()) {
      v.push_back(a);
    } else if (find(v.begin(), v.end(), b) == v.end()) {
      v.push_back(b);
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  solve();
  for (int i=0;i<ans.size();i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
