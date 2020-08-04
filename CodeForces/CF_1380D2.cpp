#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll n, m, fc, fr, bc;
ll a[200002];
ll b[200002];
vector<vector<ll> > gaps;

int set_gaps() {
  int prev = 1;
  for (int i=1;i<m+2;i++) {
    vector<ll> gap; int j;
    for (j=prev;j<=n;j++) {
      if (i <= m && a[j] == b[i])
        break;
      gap.push_back(j);
      //cout << a[j];
    }
    //cout << endl;
    if (j == n + 1 && i < m+1) return 0;
    if (gap.size() > 0) gaps.push_back(gap);
    prev = j+1;
  }
  return 1;
}

ll solve() {
  if (set_gaps() == 0) return -1;
  ll res = 0;
  for (int i=0;i<gaps.size();i++) {
    if (gaps[i].size() == 1) {
      //cout << gaps[i][0] << endl;
      if (a[gaps[i][0]] < a[gaps[i][0]-1] || a[gaps[i][0]] < a[gaps[i][0]+1])
        res = fr == 1 && fc < bc ? res + fc : res + bc;
      else if (fr == 1)
        res += fc;
      else {
        return -1;
      }
      //cout << res << endl;
    } else {
      ll mx = 0;
      //cout << mx << endl;
      for (int j=0;j<gaps[i].size();j++) {
        int g = gaps[i][j];
        mx = max(mx, a[g]);
      }
      //cout << mx << endl;
      if (mx < a[gaps[i][0]-1] || mx < a[gaps[i][gaps[i].size()-1]+1]) {
        if (gaps[i].size() / fr > 0) {
          if (bc * fr < fc) {
            res += gaps[i].size() * bc;
          } else {
            res += (gaps[i].size() / fr) * fc;
            res += bc * (gaps[i].size() - fr * (gaps[i].size() / fr));
          }
        } else {
          res += gaps[i].size() * bc;
        }
      } else {
        //cout << gaps[i].size() << " " << fr << endl;
        if (gaps[i].size() / fr <= 0) return -1;
        else {
          if (bc * fr < fc) {
            res += fc + (gaps[i].size() - fr) * bc;
          } else {
            res += (gaps[i].size() / fr) * fc;
            res += bc * (gaps[i].size() - fr * (gaps[i].size() / fr));
          }
        }
      }
      //cout << res << endl;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  cin >> fc >> fr >> bc;
  for (int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for (int i=1;i<=m;i++) {
    cin >> b[i];
  }
  a[0] = -1; a[n+1] = -1;
  cout << solve() << endl;
  return 0;
}
