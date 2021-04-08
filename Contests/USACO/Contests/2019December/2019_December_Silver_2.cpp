#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <utility>

typedef long long ll;

using namespace std;

struct cow {
  ll w, x;
  int d;
  ll finish;
};

ll n, l;
cow arr[50001];

ll total_weight = 0;

bool cmp(cow a, cow b) {
  return a.x < b.x;
}

bool cmp_times(pair<ll, ll> a, pair<ll, ll> b) {
  return a.first < b.first;
}
ll solve() {
  ll res = 0;
  sort(arr, arr+n, cmp);
  vector<pair<ll, ll> > times;
  vector<ll> ltimes; vector<ll> rtimes;
  for (int i=0;i<n;i++) {
    if (arr[i].d < 0) {
      ltimes.push_back(i);
      arr[i].finish = arr[i].x;
    }
    else {
      rtimes.push_back(i);
      arr[i].finish = l - arr[i].x;
    }
  }
  for (int i=0;i<ltimes.size();i++) {
    pair<ll, ll> pr (arr[ltimes[i]].finish, arr[i].w);
    times.push_back(pr);
  }
  for (int i=0;i<rtimes.size();i++) {
    pair<ll, ll> pr (arr[rtimes[i]].finish, arr[ltimes.size() + i].w);
    times.push_back(pr);
  }
  sort(times.begin(), times.end(), cmp_times);
  ll time = 0; int j = 0;
  while (total_weight > 0) {
    total_weight -= 2 * times[j].second;
    time = times[j].first;
    //cout << arr[times[j]].finish << endl;
    j++;
  }
  cout << time << endl;
  queue<ll> q;
  for (int i=0;i<n;i++) {
    if (arr[i].d == 1)
      q.push(arr[i].x);
    else {
      while (q.size() && q.front() + 2 * time < arr[i].x) q.pop();
      res += q.size();
    }
  }
  return res;
}

int main() {
  ofstream fout ("meetings.out");
  ifstream fin ("meetings.in");
  fin >> n >> l;
  for (int i=0;i<n;i++) {
    cow a;
    fin >> a.w >> a.x >> a.d;
    arr[i] = a;
    //cout << a.w << endl;
    total_weight += a.w;
    //cout << total_weight << endl;
  }
  fout << solve() << endl;

  return 0;
}
