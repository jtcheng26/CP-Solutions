#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;
char a[1001][1001];
pair<int, int> A;
pair<int, int> B;
string ans;

bool solve() {
  pair<int, int> parent[n][m];
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      parent[i][j].F = -1;
      parent[i][j].S = -1;
    }
  }
  queue<pair<int, int> > q;
  parent[A.F][A.S] = mp(-1, -1);
  q.push(mp(A.F, A.S));
  while (!q.empty()) {
    pair<int, int> top = q.front();
    q.pop();
    if (top.F > 0 && a[top.F-1][top.S] != '#' && parent[top.F-1][top.S].F == -1) {
      parent[top.F-1][top.S] = mp(top.F, top.S);
      q.push(mp(top.F-1, top.S));
    }
    if (top.F < n - 1 && a[top.F+1][top.S] != '#' && parent[top.F+1][top.S].F == -1) {
      parent[top.F+1][top.S] = mp(top.F, top.S);
      q.push(mp(top.F+1, top.S));
    }
    if (top.S > 0 && a[top.F][top.S-1] != '#' && parent[top.F][top.S-1].F == -1) {
      parent[top.F][top.S-1] = mp(top.F, top.S);
      q.push(mp(top.F, top.S-1));
    }
    if (top.S < m - 1 && a[top.F][top.S+1] != '#' && parent[top.F][top.S+1].F == -1) {
      parent[top.F][top.S+1] = mp(top.F, top.S);
      q.push(mp(top.F, top.S+1));
    }
  }
  stack<char> st;
  if (parent[B.F][B.S].F == -1) return false;
  pair<int, int> curr = mp(B.F, B.S);
  while (!(curr.F == A.F && curr.S == A.S)) {
    if (parent[curr.F][curr.S].F < curr.F) {
      st.push('D');
    } else if (parent[curr.F][curr.S].F > curr.F) {
      st.push('U');
    } else if (parent[curr.F][curr.S].S < curr.S) {
      st.push('R');
    } else {
      st.push('L');
    }
    int pf = parent[curr.F][curr.S].F;
    int ps = parent[curr.F][curr.S].S;
    curr.F = pf;
    curr.S = ps;
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return true;
}

int main() {
  cin >> n >> m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        A.F = i;
        A.S = j;
      } else if (a[i][j] == 'B') {
        B.F = i;
        B.S = j;
      }
    }
  }
  bool res = solve();
  if (res) {
    cout << "YES" << "\n";
    cout << ans.length() << "\n";
    cout << ans << "\n";
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
