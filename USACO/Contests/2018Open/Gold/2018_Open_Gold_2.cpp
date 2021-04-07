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

int n, m;
vector<int> a[100001];
int in[100001];
vector<int> out[100001];
vector<int> res;

bool valid(int l) {
  //cout << l << "\n";
  res.clear();
  for (int i=1;i<=n;i++) {
    out[i].clear();
    in[i] = 0;
  }
  for (int i=0;i<=l;i++) {
    for (int j=0;j<a[i].size()-1;j++) {
      out[a[i][j]].pb(a[i][j+1]);
      in[a[i][j+1]]++;
    }
  }
  set<int> q;
  for (int i=1;i<=n;i++) {
    if (in[i] == 0) q.insert(i);
  }
  int cnt = 0;
  while (!q.empty()) {
    int top = *(q.begin());
    q.erase(q.begin());
    res.pb(top);
    for (int adj : out[top]) {
      //if (in[adj] == 0) return false;
      in[adj]--;
      if (in[adj] == 0) {
        q.insert(adj);
      }
    }
    cnt++;
  }
  if (cnt < n) return false;
  return true;
}

vector<int> solve() {
  int l = 0, r = m;
  vector<int> ans;
  while (l < r) {
    int mid = (l + r) / 2;
    if (valid(mid)) {
      ans = res;
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return ans;
}

int main() {
  ofstream cout ("milkorder.out");
  ifstream cin ("milkorder.in");
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int k;
    cin >> k;
    for (int j=0;j<k;j++) {
      int b;
      cin >> b;
      a[i].pb(b);
    }
  }
  vector<int> ans = solve();
  for (int j=0;j<ans.size();j++) {
    cout << ans[j] << (j == ans.size() - 1 ? "\n" : " ");
  }
  return 0;
}
