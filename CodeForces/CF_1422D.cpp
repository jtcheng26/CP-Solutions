#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

using namespace std;

struct Graph {
  int n;
  vector<pair<int, int> > adj[100005];
  const int INF = 1000000007;
  int dist[100005];

  void init(int num) { n = num; for (int i=0;i<=n;i++) adj[i].clear(); } // clear tree
  void add_edge(int a, int b, int c) { adj[a].pb(mp(c, b)); adj[b].pb(mp(c, a)); } // add edge

  int dijkstra(int root) {
    bool visited[n];
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    for (int i=0;i<n;i++) {
      dist[i] = INFI; visited[i] = false;
    }
    dist[root] = 0;
    pair<int, int> p(dist[root], root); pq.push(p);
    while (pq.size() > 0) {
      pair<int, int> u = pq.top(); pq.pop();
      int idx = u.second;
      if (visited[idx]) continue; visited[idx] = true;
      for (auto child : adj[idx]) {
        if (visited[child.second]) continue;
        int d = dist[idx] + child.first; // replace 1 w/ weight of edge
        if (dist[child.second] > d) dist[child.second] = d;
        pair<int, int> node(dist[child.second], child.second); pq.push(node);
      }
    }
    return dist[n-1];
  }
};

struct pt {
  int x, y;
  int idx;
};
int n, m;
pt startPt, endPt;
pt pts[100001];
Graph g;

bool cmpX(pt a, pt b) {
  return a.x < b.x;
}

bool cmpY(pt a, pt b) {
  return a.y < b.y;
}

int solve() {
  int res = 1000000001;
  g.init(m+2);
  for (int i=0;i<m;i++) {
    int distStart = min(abs(startPt.x - pts[i].x), abs(startPt.y - pts[i].y));
    g.add_edge(0, pts[i].idx, distStart);
    int distEnd = abs(endPt.x - pts[i].x) + abs(endPt.y - pts[i].y);
    g.add_edge(m+1, pts[i].idx, distEnd);
    //cout << pts[i].x << " " << pts[i].y << " " << distStart << " " << distEnd << endl;
  }
  g.add_edge(0, m+1, abs(startPt.x - endPt.x) + abs(startPt.y - endPt.y));
  sort(pts, pts+m, cmpX);
  for (int i=1;i<m;i++) {
    g.add_edge(pts[i].idx, pts[i-1].idx, abs(pts[i].x-pts[i-1].x));
    //cout << pts[i].idx << " " << pts[i-1].idx << " " << abs(pts[i].x-pts[i-1].x) << endl;
  }
  sort(pts, pts+m, cmpY);
  for (int i=1;i<m;i++) {
    g.add_edge(pts[i].idx, pts[i-1].idx, abs(pts[i].y-pts[i-1].y));
    //cout << pts[i].idx << " " << pts[i-1].idx << " " << abs(pts[i].y-pts[i-1].y) << endl;
  }
  return g.dijkstra(0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  cin >> startPt.x >> startPt.y >> endPt.x >> endPt.y;
  for (int i=0;i<m;i++) {
    cin >> pts[i].x >> pts[i].y;
    pts[i].idx = i + 1;
  }
  cout << solve() << "\n";
  return 0;
}
