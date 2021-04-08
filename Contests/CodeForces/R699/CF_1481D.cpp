#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
char edge[1001][1001];
int ain[1001];
int aout[1001];

vector<int> solve() {
  vector<int> res;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (edge[i][j] == edge[j][i]) {
        vector<int> path;
        path.pb(i);
        path.pb(j);
        int curr = 0;
        for (int i=0;i<m+1;i++) {
          res.pb(path[curr]);
          curr = !curr;
        }
        return res;
      } else if (m % 2 == 1) {
        vector<int> path;
        path.pb(i);
        path.pb(j);
        int curr = 0;
        for (int i=0;i<m+1;i++) {
          res.pb(path[curr]);
          curr = !curr;
        }
        return res;
      }
    }
  }
  for (int i=0;i<n;i++) {
    ain[i] = -1;
    aout[i] = -1;
  }
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      if (edge[i][j] == 'a') {
        aout[i] = j;
        ain[j] = i;
      } else if (edge[j][i] == 'a') {
        ain[i] = j;
        aout[j] = i;
      }
    }
  }
  for (int i=0;i<n;i++) {
    if (aout[i] != -1 && ain[i] != -1) {
      vector<int> path;
      if (m % 4 == 0) {
        path.pb(i);
        path.pb(aout[i]);
        path.pb(i);
        path.pb(ain[i]);
      } else {
        path.pb(ain[i]);
        path.pb(i);
        path.pb(aout[i]);
        path.pb(i);
      }
      int curr = 0;
      for (int i=0;i<m+1;i++) {
        res.pb(path[curr]);
        curr = (curr + 1) % 4;
      }
      return res;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        cin >> edge[i][j];
      }
    }
    vector<int> ans = solve();
    if (ans.size() == 0) {
      cout << "NO" << "\n";
    } else {
      cout << "YES" << "\n";
      for (int i=0;i<int(ans.size());i++) {
        cout << (ans[i] + 1) << (i == int(ans.size()) - 1 ? "\n" : " ");
      }
    }
  }
  return 0;
}
