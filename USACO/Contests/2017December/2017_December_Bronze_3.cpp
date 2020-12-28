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
  int time;
  string cow;
  int sign;
  int change;
};

bool cmp(event a, event b) {
  return a.time < b.time;
}

int n;
event events[101];

void printEvent(event e) {
  cout << "event" << "\n";
  cout << "time: " << e.time << "\n";
  cout << "cow: " << e.cow << "\n";
  cout << "sign: " << e.sign << "\n";
  cout << "change: " << e.change << "\n";
}

int solve() {
  int res = 0;
  sort(events, events+n, cmp);
  bool on[3];
  int cnt[3];
  map<string, int> idx;
  on[0] = on[1] = on[2] = true;
  cnt[0] = cnt[1] = cnt[2] = 7;
  idx["Mildred"] = 0;
  idx["Elsie"] = 1;
  idx["Bessie"] = 2;
  for (int i=0;i<n;i++) {
      //printEvent(events[curr]);
    int k = idx[events[i].cow];
    cnt[k] += events[i].sign * events[i].change;
    int mx = 0;
    for (int j=0;j<3;j++) {
      mx = max(mx, cnt[j]);
    }
    bool flag = false;
    for (int j=0;j<3;j++) {
      if (cnt[j] == mx) {
        if (!on[j]) flag = true;
        on[j] = true;
      } else {
        if (on[j]) flag = true;
        on[j] = false;
      }
    }
    if (flag) res++;
  }
  return res;
}

int main() {
  ofstream cout ("measurement.out");
  ifstream cin ("measurement.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> events[i].time >> events[i].cow;
    string change;
    cin >> change;
    if (change[0] == '+') events[i].sign = 1;
    else events[i].sign = -1;
    events[i].change = stoi(change.substr(1));
  }
  cout << solve() << endl;
  return 0;
}
