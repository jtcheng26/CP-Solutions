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

int n;
ll a[100001];

ll solve() {
  ll res = 0;
  queue<int> lastPos; // indexes of non-zero positive numbers
  for (int i=0;i<n;i++) {
    if (a[i] > 0) lastPos.push(i);
    else {
      if (lastPos.size() == 0) continue;
      else {
        while (lastPos.size() > 0 && a[i] < 0) {
          int u = lastPos.front();
          ll mn = min(abs(a[u]), abs(a[i]));
          a[i] += mn;
          a[u] -= mn;
          if (a[u] == 0) lastPos.pop();
        }
      }
    }
  }
  for (int i=0;i<n;i++) {
    if (a[i] > 0)
      res += a[i];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << solve() << endl;
  }
  return 0;
}
