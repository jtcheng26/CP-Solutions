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

int n, k;
int a[50001];
vector<int> of[51];
vector<int> out[51];

int solve() {
  if (n == 1) return 0;
  int dist[n];
  bool visited[n];
  set<pair<int, int> > q;
  for (int i=0;i<n;i++) {
    dist[i] = -1;
    visited[i] = false;
  }
  dist[0] = 0;
  q.insert(mp(0, 0));
  while (!q.empty()) {
    pair<int, int> p = *(q.begin());
    int top = p.S;
    visited[top] = true;
    if (top == n - 1) return p.F;
    q.erase(q.begin());
    for (int adjColor : out[a[top]]) {
      for (int adj : of[adjColor]) {
        if (visited[adj]) continue;
        if (dist[adj] == -1 || (dist[top] + abs(top - adj) < dist[adj])) {
          if (dist[adj] != -1)
            q.erase(q.find(mp(dist[adj], adj)));
          dist[adj] = dist[top] + abs(top - adj);
          q.insert(mp(dist[adj], adj));
        }
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i=0;i<n;i++) {
    int color;
    cin >> color;
    a[i] = color;
    of[color].pb(i);
  }
  for (int i=1;i<=k;i++) {
    for (int j=1;j<=k;j++) {
      char c;
      cin >> c;
      if (c == '1') {
        out[i].pb(j);
      }
    }
  }
  cout << solve() << endl;
  return 0;
}
