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

int n, m, k;
int a[100001];
int loc[100001] = {0};
bool visited[100001] = {0};
pair<int, int> q[101];
vector<int> inCycle[100001];
int numCycle[100001];
int idx[100001];
int numC = 0;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}

int dfs(int node) {
  visited[node] = true;
  if (visited[loc[node]]) {
    numCycle[node] = numC;
    inCycle[numC].pb(node);
    idx[node] = inCycle[numC].size() - 1;
    return 1;
  }
  else {
    int nxt = dfs(loc[node]);
    if (nxt > 0) {
      numCycle[node] = numC;
      inCycle[numC].pb(node);
      idx[node] = inCycle[numC].size() - 1;
      return nxt + 1;
    }
  }
  return 0;
}

void solve() {
  for (int i=1;i<=n;i++) {
    int end = i;
    for (int j=0;j<m;j++) {
      if (q[j].F <= end && end <= q[j].S) {
        end = q[j].F + q[j].S - end;
      }
    }
    loc[i] = end;
  }
  //for (int i=1;i<=n;i++) cout << loc[i] << (i == n ? "\n" : " ");
  int seen[100001] = {0};
  ll maxCycle = 1;
  for (int i=1;i<=n;i++) {
    if (!visited[i]) {
      numC++;
      maxCycle = lcm(maxCycle, dfs(i));
    }
  }
  int step = k % maxCycle;
  for (int i=1;i<=n;i++) {
    int sz = inCycle[numCycle[i]].size();
    //cout << ((idx[i] + sz - 1) % sz + step % sz) % sz << "\n";
    int l = idx[i] - step % sz;
    while (l < 0) l += sz;
    a[inCycle[numCycle[i]][l % sz]] = i;
    //a[inCycle[numCycle[i]][sz - 1 - (step >= sz ? step % sz : step - 1)]] = i;
  }
}

int main() {
  ofstream cout ("swap.out");
  ifstream cin ("swap.in");
  cin >> n >> m >> k;
  for (int i=1;i<=n;i++) a[i] = i;
  for (int i=0;i<m;i++) cin >> q[i].F >> q[i].S;
  solve();
  for (int i=1;i<=n;i++) cout << a[i] << "\n";
  return 0;
}
