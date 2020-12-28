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

struct ball {
  int x, y;
};

int n, k;
ball a[101];

int dist(ball a, ball b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    int cnt = 0;
    for (int j=0;j<n;j++) {
      if (dist(a[i], a[j]) <= k)
        cnt++;
    }
    if (cnt == n) return 1;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
      cin >> a[i].x >> a[i].y;
    }
    cout << solve() << "\n";
  }
  return 0;
}
