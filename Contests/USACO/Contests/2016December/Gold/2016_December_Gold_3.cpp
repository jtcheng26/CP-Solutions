#include <iostream>
#include <fstream>
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
pair<int, int> start;
pair<int, int> last;
vector<int> adj[200005];
map<int, int> conv;

int solve() {
  int dist[200005];
  queue<int> q;
  q.push(conv[start.F]);
  q.push(conv[start.S + 100001]);
  for (int i=0;i<=200004;i++) {
    dist[i] = INF;
  }
  dist[conv[start.F]] = 0;
  dist[conv[start.S + 100001]] = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    if (top == conv[last.F] || top == conv[last.S + 100001]) return dist[top];
    for (int neighbor : adj[top]) {
      if (dist[conv[neighbor]] != INF) continue;
      dist[conv[neighbor]] = dist[top] + 1;
      q.push(conv[neighbor]);
    }
  }
  return -1;
}

int main() {
  ofstream cout ("lasers.out");
  ifstream cin ("lasers.in");
  cin >> n;
  int curr = 1;
  cin >> start.F >> start.S >> last.F >> last.S;
  if (conv[start.F] == 0)
    conv[start.F] = curr++;
  if (conv[start.S + 100001] == 0)
    conv[start.S + 100001] = curr++;
  if (conv[last.F] == 0)
    conv[last.F] = curr++;
  if (conv[last.S + 100001] == 0)
    conv[last.S + 100001] = curr++;
  for (int i=0;i<n;i++) {
    int x, y;
    cin >> x >> y;
    if (conv[x] == 0) conv[x] = curr++;
    if (conv[y + 100001] == 0) conv[y + 100001] = curr++;
    adj[conv[x]].pb(y + 100001);
    adj[conv[y + 100001]].pb(x);
  }
  cout << solve() << endl;
  return 0;
}
