#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;

ll l, n, m, d;
ll w[100001];

ll solve() {
  ll res = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
  for (int i=0;i<n;i++) {
    pair<ll, ll> p(w[i], i);
    pq.push(p);
  }
  ll taken[n];
  for (int i=0;i<n;i++) taken[i] = 0;
  for (int i=0;i<l;i++) {
    pair<ll, ll> a = pq.top();
    pq.pop();
    cout << taken[a.second] << " " << a.second << endl;
    if (taken[a.second] > 0) a.first = a.first + w[a.second];
    taken[a.second]++;
    pq.push(a);
    res = a.first;
  }
  cout << res << endl;
  priority_queue<ll, vector<ll>, greater<ll> > pq2;
  for (int i=0;i<min(n, m);i++) pq2.push(0);
  while (taken[pq.top().second] == 0) pq.pop();
  while (pq.top().first > 0) {
    ll drier = pq2.top();
    pq2.pop();
    pair<ll, ll> a = pq.top();
    pq.pop();
    a.first -= w[a.second];
    drier += d;
    pq2.push(drier);
    pq.push(a);
    //cout << drier << endl;
  }
  return res + pq2.top();
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  //ifstream cin ("test.out");
  //ofstream cout ("2020Q1.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> l >> n >> m >> d;
    for (int j=0;j<n;j++) {
      cin >> w[j];
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
