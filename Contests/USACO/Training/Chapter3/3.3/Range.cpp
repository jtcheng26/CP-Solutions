/*
   LANG: C++11
   PROG: range
*/
//6:42
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int field[251][251];
vector<pair<int, ll> > ans;
// number of ones in square w/ top left corner at 0, 0 and bottom right at i, j
int oneCnt[251][251];

ll countSquares(int sz) {
  // top left corner of square
  ll cnt = 0;
  int req = sz * sz; // required ones for valid square
  for (int i=sz-1;i<n;i++) {
    for (int j=sz-1;j<n;j++) {
      // get ones in any square in O(1) time
      int ones = 0; // ones in square
      if (i - sz < 0 && j - sz < 0)
        ones = oneCnt[i][j];
      else if (i - sz < 0)
        ones = oneCnt[i][j] - oneCnt[i][j-sz];
      else if (j - sz < 0)
        ones = oneCnt[i][j] - oneCnt[i-sz][j];
      else
        ones = oneCnt[i][j] - oneCnt[i-sz][j] - oneCnt[i][j-sz] + oneCnt[i-sz][j-sz];
      if (ones == req) cnt++;
    }
  }
  return cnt;
}

int solve() {
  if (field[0][0] == 1) oneCnt[0][0] = 1;
  else oneCnt[0][0] = 0;
  // precompute the number of ones in each prefix square
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (i == 0 && j == 0) continue;
      if (i != 0 && j != 0) {
        oneCnt[i][j] = oneCnt[i-1][j] + oneCnt[i][j-1] - oneCnt[i-1][j-1];
        oneCnt[i][j] += field[i][j];
      }
      if (i == 0)
        oneCnt[i][j] = oneCnt[i][j-1] + field[i][j];
      if (j == 0)
        oneCnt[i][j] = oneCnt[i-1][j] + field[i][j];
    }
  }
  for (int i=2;i<=n;i++) {
    ll cnt = countSquares(i);
    if (cnt > 0) ans.pb(mp(i, cnt));
    if (cnt == 1) break;
  }
  return 0;
}

int main() {
  ofstream cout ("range.out");
  ifstream cin ("range.in");
  cin >> n;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      char c;
      cin >> c;
      field[i][j] = c - '0';
    }
  }
  solve();
  for (int i=0;i<ans.size();i++) {
    cout << ans[i].F << " " << ans[i].S << endl;
  }
  return 0;
}
