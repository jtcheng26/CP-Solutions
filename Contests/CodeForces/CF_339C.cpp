#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
vector<int> weights;
bool visited[21][11][1001]; // balance, prev, dist
stack<int> ans;

bool dfs(int b, int prev, int dist) {
  //cout << b << " " << prev << " " << dist << "\n";
  if (dist > n) return true;
  if (visited[b][prev][dist]) return false;
  for (int w : weights) {
    if (w == prev) continue;
    if (b > 10 && b - w < 10) {
      if (dfs(b - w, w, dist + 1)) {
        ans.push(w);
        return true;
      }
    }
    if (b < 10 && b + w > 10) {
      if (dfs(b + w, w, dist + 1)) {
        ans.push(w);
        return true;
      }
    }
    if (b == 10) {
      if (dfs(b + w, w, dist + 1)) {
        ans.push(w);
        return true;
      }
    }
  }
  visited[b][prev][dist] = false;
  return false;
}

bool solve() {
  int res = 0;
  for (int i=0;i<=20;i++)
  for (int j=0;j<=10;j++)
  for (int k=0;k<=n;k++)
    visited[i][j][k] = false;
  return dfs(10, 0, 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  for (int i=1;i<=10;i++) {
    char c;
    cin >> c;
    if (c - '0' == 1) weights.pb(i);
  }
  cin >> n;
  bool poss = solve();
  cout << (poss ? "YES" : "NO") << "\n";
  if (poss)
    for (int i=0;i<n;i++) {
      cout << ans.top() << (i == n-1 ? "\n" : " ");
      ans.pop();
    }
  return 0;
}
