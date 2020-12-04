#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct event {
  bool start;
  int x, y;
  int j;
};

struct SegTree {
  int n = 500001;  // array size
  int t[1000001] = {0};
  map<int, bool> converted;
  map<int, int> conv;
  int curr = 0;

  void setVals(vector<int> v) {
    sort(v.begin(), v.end());
    for (int val : v) {
      if (!converted[val]) {
        conv[val] = curr++;
        converted[val] = true;
      }
    }
  }

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
  }

  void ptUpdate(int loc, int value) {  // set value at position p
    int p = conv[loc];
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
  }

  int rngMin(int left, int right) {  // min on interval [l, r)
    int l = conv[left];
    int r = conv[right];
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res = min(res, t[l++]);
      if (r&1) res = min(res, t[--r]);
    }
    return res;
  }
};

int n, p;
event events[200001];

bool cmp(event a, event b) {
  if (a.x == b.x) {
    if (a.y == b.y) {
      return a.start && !b.start;
    }
    return a.y < b.y;
  }
  return a.x < b.x;
}

int solve() {
  SegTree st;
  st.init();
  vector<int> nums;
  nums.pb(0);
  for (int i=0;i<2*p;i++) {
    nums.pb(events[i].y);
    nums.pb(events[i].y+1);
  }
  nums.pb(n);
  nums.pb(n+1);
  st.setVals(nums);
  sort(events, events+2*p, cmp);
  int ans[p];
  for (int i=0;i<p;i++) ans[i] = 2000000005;
  for (int i=0;i<2*p;i++) {
    if (events[i].x > n) break;
    //cout << (e.start ? "start" : "end") << " index " << e.j << " x " << e.x << " y " << e.y << "\n";
    if (events[i].start) {
      ans[events[i].j] = min(ans[events[i].j], events[i].x + events[i].y + st.rngMin(0, events[i].y+1));
    } else {
      st.ptUpdate(events[i].y, min(st.t[st.n + st.conv[events[i].y]], ans[events[i].j] - (events[i].x + events[i].y)));
    }
    //cout << "dist " << ans[e.j] << "\n";
    //cout << "tree curr " << st.t[st.n + st.conv[e.y]] << "\n";
  }
  return n + n + st.rngMin(0, n+1);
}

int main() {
  ofstream cout ("boards.out");
  ifstream cin ("boards.in");
  cin >> n >> p;
  for (int i=0;i<p;i++) {
    cin >> events[i].x >> events[i].y;
    events[i].start = true;
    events[i].j = i;
    cin >> events[p+i].x >> events[p+i].y;
    events[p+i].start = false;
    events[p+i].j = i;
  }
  cout << solve() << endl;
  return 0;
}
