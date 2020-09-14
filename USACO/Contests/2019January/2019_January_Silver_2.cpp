// Time - 37:49

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 100000007

typedef long long ll;

using namespace std;

ll n;
string arr[1001];
bool ice[1000001];
vector<int> edges[1000001];
int comps[1000001];

void set_graph() {
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      ice[i*n+j] = false;
      if (arr[i][j] == '#') ice[i*n+j] = true;
      if (j > 0) {
        if (arr[i][j] == '#' && arr[i][j-1] == '#') {
          edges[i*n+j].push_back(i*n+j-1);
          edges[i*n+j-1].push_back(i*n+j);
        }
      }
      if (i > 0) {
        if (arr[i][j] == '#' && arr[i-1][j] == '#') {
          edges[i*n+j].push_back((i-1)*n+j);
          edges[(i-1)*n+j].push_back(i*n+j);
        }
      }
    }
  }
}

pair<int, int> bfs(int comp, int ind) {
  queue<int> q;
  pair<int, int> ans(0, 0);
  q.push(ind);
  comps[ind] = comp;
  while (q.size() > 0) {
    int u = q.front();
    q.pop();
    //cout << u << " " << comps[u] << endl;
    ans.first++;
    ans.second += (4 - edges[u].size());
    for (int i=0;i<edges[u].size();i++) {
      if (comps[edges[u][i]] == -1) {
        comps[edges[u][i]] = comp;
        q.push(edges[u][i]);
      }
    }
  }
  return ans;
}

pair<int, int> solve() {
  pair<int, int> res(0, INFI);
  set_graph();
  for (int i=0;i<n*n;i++) comps[i] = -1;
  int comp = 0;
  for (int i=0;i<n*n;i++) {
    if (ice[i] && comps[i] == -1) {
      pair<int, int> p = bfs(++comp, i);
      //cout << p.first << " " << p.second << endl;
      if (p.first >= res.first) {
        if (p.first > res.first || p.second < res.second) {
          res.first = p.first;
          res.second = p.second;
        }
      }
    }
  }
  return res;
}

int main() {
  ofstream cout ("perimeter.out");
  ifstream cin ("perimeter.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> arr[i];
  }
  pair<int, int> ans = solve();
  cout << ans.first << " " << ans.second << endl;
  return 0;
}
