#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef unsigned long long ll;

using namespace std;

ll n, p;
ll c[100000];

void compute(ll* b) {
  c[0] = b[0];
  for (ll i=1;i<n;i++) {
    c[i] = c[i-1] + b[i];
  }
  //cout << c[n-1] << endl;
}

int bin_search(ll l, ll* b) {
  if (b[l] > p) return -1;
  ll res = l; ll r = n; ll ol = l;
  while (l < r) {
    ll mid = (r + l) / 2;
    //cout << res << endl;
    ll pos = ol==0 ? c[mid] : c[mid] - c[ol-1];
    //cout << mid << " " << pos << endl;
    if (pos > p) {
      r = mid;
    } else if (pos < p) {
      l = mid + 1; res = mid;
      //cout << "l" << l << endl;
    } else {
      return mid;
    }
  }
  if (b[res] > p) return -1;
  return res;
}

ll solve(ll* b) {
  ll res = 0;
  /*
  for (int i=0;i<n;i++) {
    cout << b[i] << " " << c[i] << endl;
  }
  */
  int l, r;
  for (ll i=0;i<n;i++) {
    l = i; r = bin_search(l, b);
    if (r < 0) continue;
    else if (i == n-1) res++;
    else {
      res += r - l + 1;
    }
    //cout << l << " " << r << " " << res << endl;
    //cout << l << " " << r << endl;
    //cout << l << " " << r << " " << res << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream fin ("Price_input.txt");
  ofstream fout ("2016Q3.txt");
  ll t;
  fin >> t;//
  for (ll i=1;i<=t;i++) {
    fin >> n >> p;
    ll b[n];
    for (ll j=0;j<n;j++) {
      fin >> b[j];
    }
    compute(b);
    fout << "Case #" << i << ": " << solve(b) << endl;//
  }
  return 0;
}
