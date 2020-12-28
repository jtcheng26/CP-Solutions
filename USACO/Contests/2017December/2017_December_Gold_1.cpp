#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, d;
int a[2][200001];
int dist[200001] = {0};

void test() {
  set<pair<int, int> > s;
  s.insert(mp(0, 1));
  s.insert(mp(5, 2));
  s.insert(mp(10, 3));
  auto it = prev(s.lower_bound(mp(6, 2)));
  cout << (*it).S << "\n";
}

void solve() {
  queue<int> q;
  set<pair<int, int> > left[2]; // a value, index
  for (int i=1;i<=2*n;i++) {
    dist[i] = -1;
  }
  for (int i=1;i<=2*n;i++) {
    if ((i > n && a[0][i] == 0) || (i <= n && a[1][i] == 0)) {
      dist[i] = 1;
      q.push(i);
    } else {
      if (i <= n) {
        left[0].insert(mp(a[1][i], i));
      } else {
        left[1].insert(mp(a[0][i], i));
      }
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    //cout << node << "\n";
    int side = node <= n;
    vector<pair<int, int> > rem;
    auto it = left[side].lower_bound(mp(a[!side][node], 2*n+1));
    if (it == left[side].begin())
      continue;
    else
      it = prev(it);
    for (it;a[!side][node] - (*it).F <= d;it--) {
      //cout << "node " << node << " visiting " << (*it).S << " " << (*it).F << "\n";
      int i = (*it).S;
      dist[i] = dist[node] + 1;
      q.push(i);
      rem.pb(*it);
      if (it == left[side].begin()) break;
    }
    for (pair<int, int> i : rem)
      left[side].erase(left[side].find(i));
  }
}

int main() {
  ofstream cout ("piepie.out");
  ifstream cin ("piepie.in");
  cin >> n >> d;
  for (int i=1;i<=2*n;i++) {
    cin >> a[0][i] >> a[1][i];
  }
  solve();
  //test();
  for (int i=1;i<=n;i++) {
    cout << dist[i] << "\n";
  }
  return 0;
}
