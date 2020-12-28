#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

struct event {
  int time;
  int id;
  int change;
};

bool cmp(event a, event b) {
  return a.time < b.time;
}

int n, g;
event events[100001];

int solve() {
  int res = 0;
  map<int, ll> change;
  multiset<ll> values;
  values.insert(0);
  sort(events, events+n, cmp);
  for (int i=0;i<n;i++) {
    int k = events[i].id;
    bool flag = false;
    ll mx = *prev(values.end());
    bool prevMax = change[k] == mx;
    if (change[k] != 0)
      values.erase(values.find(change[k]));
    change[k] += events[i].change;
    if (change[k] != 0)
      values.insert(change[k]);
    if (mx != *prev(values.end())) {
      if (*prev(values.end()) > mx) {
        if (values.count(mx) > 0)
          flag = true;
      } else if (*prev(values.end()) < mx) {
        int req = 0;
        if (*prev(values.end()) == change[k])
          req = 1;
        if (values.count(*prev(values.end())) > req || *prev(values.end()) == 0) {
          flag = true;
        }
      }
    } else {
      if (prevMax || change[k] == mx) flag = true;
    }
    if (flag) res++;
  }
  return res;
}

int main() {
  ofstream cout ("measurement.out");
  ifstream cin ("measurement.in");
  cin >> n >> g;
  for (int i=0;i<n;i++) {
    cin >> events[i].time >> events[i].id >> events[i].change;
  }
  cout << solve() << endl;
  return 0;
}
