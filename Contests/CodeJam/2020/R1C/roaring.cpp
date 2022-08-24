#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <climits>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef unsigned long long ll;

using namespace std;

ll s;
vector<ll> good;

bool isRoaring(string a) {
  for (int i=1;i<=a.length()/2;i++) {
    ll prev = stoll(a.substr(0, i));
    bool flag = true;
    int k = i;
    for (int j=i;j<a.length();j+=k) {
      if (to_string(prev + 1).length() > k)
        k++;
      if (j + k > a.length()) {
        flag = false;
        break;
      }
      if (stoll(a.substr(j, k)) != prev + 1) {
        flag = false;
      } else {
        prev = stoll(a.substr(j, k));
      }
    }
    if (flag)
      return true;
  }
  return false;
}/*
void gen() {
  ll a = 0;
  for (int i=1;i<=1000000;i++) {
    int j = i;
    int cnt = 0;
    while (to_string(a).length() < 19) {
      if (cnt > 0) {
        for (int k=0;k<j/10+1;k++) {
          a *= 10;
        }
        a *= pow(10, j / 10 + 1);
      }
      a += j;
      j++;
      cnt++;
      if (cnt >= 2 && to_string(a).length() < 19) {
        good.pb(a);
      }
      else if (to_string(a).length() >= 19)
        break;
    }
    a = 0;
  }
}*/
void gen() {
  string a = "";
  for (int i=1;i<=1000000;i++) {
    int j = i;
    int cnt = 0;
    while (a.length() < 19) {
      a += to_string(j);
      if (a.length() >= 19)
        break;
      ll ai = stoll(a);
      if (cnt >= 1)
        good.pb(ai);
      j++;
      cnt++;
    }
    a = "";
  }
}

ll solve() {
  string ans = "";
  ll res = 0;
  int l = 0;
  int r = good.size();
  while (l < r) {
    int mid = (l + r) / 2;
    if (good[mid] > s) {
      r = mid;
      res = good[mid];
    } else {
      l = mid + 1;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  gen();/*
  for (int i=1;i<=1234567;i++) {
    if (!good[i] && isRoaring(to_string(i))) {
      cout << i << "\n";
    }
  }*/
  cout << good[0] << "\n";
  cout << good.size() << "\n";
  sort(good.begin(), good.end());
  cout << good[good.size()-1] << "\n";
  for (int z=1;z<=t;z++) {
    cin >> s;
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}