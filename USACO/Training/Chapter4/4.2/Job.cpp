/*
   LANG: C++11
   PROG: job
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m1, m2;
int a[31];
int b[31];
int ans1, ans2;

int solve() {
  vector<int> atimes;
  vector<int> btimes;
  int res = 0;
  ans1 = ans2 = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
  for (int i=0;i<m1;i++) {
    pq.push(mp(a[i], i));
  }
  for (int i=0;i<n;i++) {
    pair<int, int> top = pq.top();
    pq.pop();
    atimes.pb(top.F);
    top.F += a[top.S];
    pq.push(top);
  }
  while (pq.size() > 0) pq.pop();
  for (int i=0;i<m2;i++) {
    pq.push(mp(b[i], i));
  }
  for (int i=0;i<n;i++) {
    pair<int, int> top = pq.top();
    pq.pop();
    btimes.push_back(top.F);
    top.F += b[top.S];
    pq.push(top);
  }
  for (int i=0;i<n;i++) {
    ans1 = max(ans1, atimes[i]);
    ans2 = max(ans2, atimes[i] + btimes[n - i - 1]);
  }
  return 0;
}

int main() {
  ofstream cout ("job.out");
  ifstream cin ("job.in");
  cin >> n >> m1 >> m2;
  for (int i=0;i<m1;i++) cin >> a[i];
  for (int i=0;i<m2;i++) cin >> b[i];
  solve();
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
