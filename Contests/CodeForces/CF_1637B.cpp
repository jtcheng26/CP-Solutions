#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
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

int n;
int a[100006];

ll solve() {
  ll res = 0;
  priority_queue<int> q[2];
  for (int i = 1; i < n - 1; i++) {
    q[a[i] % 2].push(a[i]);
  }
  while (!q[1].empty()) {
    if (q[0].empty()) {
      if (q[1].size() > 1 && q[1].top() > 2) {
        int top = q[1].top();
        q[1].pop();
        q[0].push(q[1].top() + 1);
        q[1].pop();
        q[1].push(top - 2);
        res++;
      } else {
        return -1;
      }
    } else {
      int top = q[0].top();
      q[0].pop();
      if (top >= 2) {
        top -= 2;
        res++;
        q[0].push(top);
        q[0].push(q[1].top() + 1);
        q[1].pop();
        if (!q[1].empty()) {
          q[0].push(q[1].top() + 1);
          q[1].pop();
        }
      } else {
        return -1;
      }
    }
  }
  while (!q[0].empty()) {
    res += q[0].top() / 2;
    q[0].pop();
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << solve() << "\n";
  }
  return 0;
}
