#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
int pascal[31][31];
vector<pair<int, int> > ans;

void solve() {
  int need = n;
  for (int r=29;r>=0;r--) {
    if ((1 << r) + r <= n) {
      int o = 0;
      need = n;
      for (int k=0;k<=r;k++) {
        if (((n - r) & (1 << k)) || !((n - r) & (1 << r))) {
          need -= (1 << k);
          if (o == 0) {
            for (int j=1;j<=k+1;j++) {
              ans.pb(mp(k+1, j));
            }
          } else {
            for (int j=k+1;j>=1;j--) {
              ans.pb(mp(k+1, j));
            }
          }
          o = !o;
        } else {
          need--;
          if (o == 0) {
            ans.pb(mp(k+1, 1));
          } else {
            ans.pb(mp(k+1, k+1));
          }
        }
      }
      for (int i=1;i<=need;i++) {
        if (o == 0) {
          ans.pb(mp(r + 1 + i, 1));
        } else {
          ans.pb(mp(r + 1 + i, r + 1 + i));
        }
      }
      break;
    }
  }/*
  int bruh = 0;
  for (pair<int, int>& p : ans) {
    if (p.F >= 31 || p.S >= 31) bruh += 1;
    else
      bruh += pascal[p.F][p.S];
  }
  if (bruh != n) {
    cout << ans.size() << "\n";
    cout << "wrong: " << bruh << " " << n << "\n";
  }*/
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  pascal[1][1] = 1;
  for (int i=2;i<=30;i++) {
    pascal[i][1] = 1;
    pascal[i][i] = 1;
    for (int j=2;j<i;j++) {
      pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    }
  }
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
      ans.clear();
      cin >> n;
      solve();
      cout << "Case #" << z << ": " << "\n";
      for (pair<int, int>& p : ans) {
        cout << p.F << " " << p.S << "\n";
      }
  }
  return 0;
}