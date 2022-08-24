#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

vector<ll> costs;
vector<ll> f; vector<ll> g;
ll n, m;

ll solve() {
  ll res = 0;
  if (m==1) {
    for (ll i=1;i<n-1;i++) {
      if (costs[i] == 0)
        return -1;
      else
        res += costs[i];
    }
    return res;
  }
  f.resize(n); g.resize(n);
  for (ll i=0;i<n;i++) {
    f[i] = -1; g[i] = -1;
  }
  ll di = 0; ll dj = di + m;
  f[0] = g[0] = 0;
  while(di < n) {
    dj = di + m;
    ll i;
    for (i=di+1;i<=dj&&i<n;i++) {
      if (f[i] == -1 || (f[di] < g[i])) {
        g[i] = f[di];
        if (costs[i] == 0)
          f[i] = 1000000001;
        else
          f[i] = g[i] + costs[i];
        if (f[i] < f[i-1] && i-1 != di && f[i-1] != 1000000001)
          f[i-1] = -2;
      }
    }
    if (di == n-1) {
      return g[n-1];
    }
    di++;
    while (f[i] == -2 && f[di] == 1000000001)
      di++;
    if (di > dj)
      return g[n-1];
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("Fumes_final.txt");
  //ofstream fout ("2020Q51_final.txt");
  ll t, c;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    costs.clear();
    f.clear(); g.clear();
    fin >> n >> m;//
    for (ll i=0;i<n;i++) {
      fin >> c;//
      costs.push_back(c);
    }
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
