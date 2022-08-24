#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, x, y; pair<ll, ll> stars[2001];

bool cmp(ll a, ll b) {
  return a < b;
}

int solve() {
  int res = 0;
  for (int i=0;i<n;i++) {
    ll dists[n];
    for (int j=0;j<n;j++) {
      ll dist = pow(stars[j].first - stars[i].first, 2) + pow(stars[j].second - stars[i].second, 2);
      dists[j] = dist;
    }
    sort(dists, dists+n, cmp);
    int cnt = 1;
    for (int j=2;j<n;j++) {
      //cout << dists[j] << endl;
      if (dists[j] != dists[j-1]) {
        res += (cnt * (cnt-1)) / 2; cnt = 1;
      } else cnt++;
    }
    res += (cnt * (cnt-1)) / 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("const_input.txt");
  ofstream fout ("2016Q1.txt");
  int t;
  fin >> t;//
  for (int i=1;i<=t;i++) {
    fin >> n;
    for (int j=0;j<n;j++) {
      fin >> x >> y;
      pair<int, int> pt(x, y);
      stars[j] = pt;
    }
    fout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
