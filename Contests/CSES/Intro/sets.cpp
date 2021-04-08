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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

ll n;
vector<int> a[2];

bool solve() {
  ll sum = (n * (n + 1)) / 2;
  if (sum % 2 == 1) return false;
  ll goal = sum / 2;
  int i = n;
  while (goal > i) {
    a[0].pb(i);
    goal -= i;
    i--;
  }
  if (goal > 0) a[0].pb(goal);
  for (int j=1;j<goal;j++) a[1].pb(j);
  for (int j=goal+1;j<=i;j++) {
    a[1].pb(j);
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  bool ans = solve();
  if (ans) {
    cout << "YES" << "\n";
    for (int i=0;i<2;i++) {
      cout << a[i].size() << "\n";
      for (int j=0;j<a[i].size();j++) {
        cout << a[i][j] << (j == a[i].size()-1 ? "\n" : " ");
      }
    }
  } else {
    cout << "NO" << "\n";
  }
  return 0;
}
