#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1000000007

typedef long long ll;

using namespace std;

struct req {
  int a, b, d;
};

int n, m;
req reqs[1001];
vector<pair<int, int> > edges[51]; // node, weight
vector<pair<int, int> > ans[51]; // same but w/o duplicates

bool cmp(req a, req b) {
  return a.d < b.d;
}

void clear_all() {
  for (int i=0;i<=50;i++) {
    edges[i].clear();
    ans[i].clear();
  }
}

int bfs(int from, int to) {
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > visit;
  bool visited[n+1];
  int dist[n+1];
  for (int i=1;i<=n;i++) {
    visited[i] = false;
    dist[i] = INFI;
  }
  dist[from] = 0;
  pair<int, int> p(dist[from], from);
  visit.push(p);
  while (visit.size() > 0) {
    int u = visit.top().second;
    visit.pop();
    visited[u] = true;
    if (u == to) break;
    for (int i=0;i<edges[u].size();i++) {
      if (!visited[edges[u][i].second]) {
        dist[edges[u][i].second] = min(dist[edges[u][i].second], dist[u] + edges[u][i].first);
        pair<int, int> p2(dist[edges[u][i].second], edges[u][i].second);
        visit.push(p2);
      }
    }
  }
  //cout << from << " " << to << " " << dist[to] << endl;
  return dist[to];
}

int solve() {
  int res = 0;
  sort(reqs, reqs + m, cmp);
  for (int i=0;i<m;i++) {
    int dist = bfs(reqs[i].a, reqs[i].b);
    if (dist < reqs[i].d) return 0;
    if (dist == reqs[i].d) continue;
    pair<int, int> conn(reqs[i].d, reqs[i].b);
    pair<int, int> rconn(reqs[i].d, reqs[i].a);
    edges[reqs[i].a].push_back(conn);
    edges[reqs[i].b].push_back(rconn);
    ans[reqs[i].a].push_back(conn);
    //cout << " push " << reqs[i].a << " " << reqs[i].b << " " << reqs[i].d << endl;
    res++;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("graphs_as_a_service_input.txt");
  ofstream cout ("2019R1A.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    clear_all();
    cin >> n >> m;
    for (int i=0;i<m;i++) {
      req r;
      cin >> r.a >> r.b >> r.d;
      reqs[i] = r;
    }
    int res = solve();
    if (res == 0) {
      cout << "Case #" << i << ": " << "Impossible" << endl;
      continue;
    }
    cout << "Case #" << i << ": " << res << endl;
    for (int i=1;i<=n;i++) {
      for (int j=0;j<ans[i].size();j++) {
        cout << i << " " << ans[i][j].second << " " << ans[i][j].first << endl;
      }
    }
  }
  return 0;
}
