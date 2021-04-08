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
  int time, x;
  int start; // x location where event began if not ignored
};

int n;
event events[100001];

int solve() {
  int res = 0;
  int curr = 0;
  events[0].start = 0;
  if (n == 1 || abs(events[0].x) + events[0].time <= events[1].time)
    res++;
  for (int i=1;i<n;i++) {
    ll currEnd = (ll)abs(events[curr].x - events[curr].start) + (ll)events[curr].time;
    if (currEnd > events[i].time) {
      if (min(events[curr].x, events[curr].start) <= events[i].x && events[i].x <= max(events[curr].x, events[curr].start)) {
        int dist = abs(events[curr].start - events[i].x);
        if (events[i].time <= (ll)dist + (ll)events[curr].time && (i == n - 1 || events[i+1].time >= (ll)dist + (ll)events[curr].time))
          res++;
      }
    } else {
      events[i].start = events[curr].x;
      if (i == n - 1 || (ll)abs(events[i].x - events[i].start) + (ll)events[i].time <= events[i+1].time)
        res++;
      curr = i;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> events[i].time >> events[i].x;
    }
    cout << solve() << "\n";
  }
  return 0;
}
