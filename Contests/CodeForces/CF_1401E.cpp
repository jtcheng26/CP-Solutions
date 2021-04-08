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

struct SegTree {
  int n = 1000001;  // array size
  int t[2000002] = {0};

  void init() {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
  }

  void ptUpdate(int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  }

  ll rngSum(int l, int r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
  }
};

struct Event {
  int x1, y1, y2;
  bool vert; // vertical ?
  int lr; // 0 == left, 1 == right
};

bool cmp(Event a, Event b) {
  //cout << "cmp" << endl;
  if (a.x1 == b.x1) {
    if (a.vert) {
      if (b.lr == 0) return false;
      else return true;
    } else if (b.vert) {
      if (a.lr == 0) return true;
      else return false;
    }
    if (a.lr == 1) return false;
    else if (b.lr == 1) return true;
  }
  return a.x1 < b.x1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<Event> events;
  SegTree st;
  st.init();
  ll res = 1;
  for (int i=1;i<=n;i++) {
    Event e1; Event e2;
    e1.vert = false; e2.vert = false;
    e1.lr = 0; e2.lr = 1;
    cin >> e1.y1 >> e1.x1 >> e2.x1;
    e2.y1 = e1.y1;
    events.pb(e1);
    events.pb(e2);
    if (e2.x1 - e1.x1 == 1000000) res++;
  }
  for (int i=1;i<=m;i++) {
    Event e1;
    e1.vert = true;
    e1.lr = -1;
    cin >> e1.x1 >> e1.y1 >> e1.y2;
    events.pb(e1);
    if (e1.y2 - e1.y1 == 1000000) res++;
  }
  //cout << "sorting " << events.size() << endl;
  sort(events.begin(), events.end(), cmp);
  //cout << "sorted" << endl;
  //cout << events[0].y1 << " " << events[0].vert << " " << events[1].y1 << " " << events[1].vert << endl;
  for (Event e : events) {
    //cout << "b" << endl;
    if (!e.vert) {
      if (e.lr == 0) {
        //cout << "upd" << endl;
        st.ptUpdate(e.y1, 1);
      } else
        st.ptUpdate(e.y1, 0);
    } else {
      res += st.rngSum(e.y1, e.y2 + 1);
    }
    //cout << " x: " << e.x1 << " y: " << e.y1 << " y2: " << e.y2 << " vertical: " << e.vert << " res: " << res << endl;
  }
  cout << res << endl;
  return 0;
}
