#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

/*

solve for each parity x
LR -> L + (R - L) / 2 treat L as R
RL -> (R - L) / 2

*/

#define L 0
#define R 1

struct robot {
  ll i, x, d;
};

int n, m;
robot a[300001];
ll ans[300001];

bool cmp(robot a, robot b) { return a.x < b.x; }

void solve() {
  sort(a, a + n, cmp);
  for (int p = 0; p < 2; p++) {
    stack<robot> st;
    for (int i = 0; i < n; i++) {
      if (a[i].x % 2 != p)
        continue;
      if (st.empty())
        st.push(a[i]);
      else if (st.top().d == R && a[i].d == L) {
        ans[a[i].i] = ans[st.top().i] = abs(a[i].x - st.top().x) / 2;
        st.pop();
      } else if (st.top().d == L && a[i].d == L) {
        ans[a[i].i] = ans[st.top().i] =
            st.top().x + abs(a[i].x - st.top().x) / 2;
        st.pop();
      } else { // top is R
        st.push(a[i]);
      }
    }
    while (!st.empty()) {
      robot top = st.top();
      st.pop();
      if (!st.empty()) {
        if (top.d == R && st.top().d == R) {
          ans[top.i] = ans[st.top().i] =
              m - top.x + abs(top.x - st.top().x) / 2;
          st.pop();
        } else {
          ans[top.i] = ans[st.top().i] =
              st.top().x + (m - top.x) + abs(top.x - st.top().x) / 2;
          st.pop();
        }
      } else {
        ans[top.i] = -1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i].x;
      a[i].i = i;
    }
    for (int i = 0; i < n; i++) {
      char d;
      cin >> d;
      if (d == 'L')
        a[i].d = L;
      else
        a[i].d = R;
    }
    solve();
    for (int i = 0; i < n; i++) {
      cout << ans[i] << (i == n - 1 ? "\n" : " ");
    }
  }
  return 0;
}
