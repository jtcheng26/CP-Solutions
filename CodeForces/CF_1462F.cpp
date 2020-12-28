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

struct event {
  int type; // 0 = l, 1 = r
  int x;
  int idx;
};

int n;
event events[400001];
int cnt[200001] = {0};

bool cmp(event a, event b) {
  if (a.x == b.x) {
    return a.type < b.type;
  }
  return a.x < b.x;
}

int solve() {
  int res = n - 1;
  sort(events, events + 2 * n, cmp);
  int lefts = 0; // left points w/o right
  int rights = 0; // right points left of curr
  for (int i=0;i<2*n;i++) {
    if (events[i].type == 0) {
      cnt[events[i].idx] = rights;
      lefts++;
    } else {
      lefts--;
      cnt[events[i].idx] += n - rights - 1 - lefts;
      rights++;
    }
  }
  //assert(lefts == 0 && rights == n);
  for (int i=0;i<n;i++) res = min(res, cnt[i]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> events[i].x >> events[n + i].x;
      events[i].type = 0;
      events[n + i].type = 1;
      events[i].idx = i;
      events[n + i].idx = i;
    }
    cout << solve() << "\n";
  }
  return 0;
}
