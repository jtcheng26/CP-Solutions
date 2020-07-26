#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

ll fc, fr, bc;
vector<ll> wp;
vector<ll> goal;
vector<ll> gap;
vector<vector<ll> > gaps;

bool in_goal(ll p) {
  for (ll i=0;i<goal.size();i++) {
    if (goal[i] == p)
      return true;
  }
  return false;
}

bool check_possible() {
  int last_i = -1; int count = 0;
  for (int i=0;i<goal.size();i++) {
    for (int j=0;j<wp.size();j++) {
      if (wp[j] == goal[i]) {
        if (j < last_i)
          return false;
        count++;
        last_i = j;
      }
    }
  }
  return count == goal.size() ? true : false;
}

void set_gaps() {
  int k = 0;
  for (ll i=0;i<wp.size();i++) {
    if (in_goal(wp[i])) {
      gaps.push_back(gap);
      gap.clear();
      continue;
    }
    else {
      gap.push_back(i);
    }
  }
  if (gap.size() > 0)
    gaps.push_back(gap);
  /*
  for (int i=0;i<gaps.size();i++) {
    for (int j=0;j<gaps[i].size();j++) {
      cout << gaps[i][j] << endl;
    }
  }
  */
}
bool erase_if_pos(int i, int j) {
  if (wp[gaps[i][j]] < wp[gaps[i][j-1]] || wp[gaps[i][j]] < wp[gaps[i][j+1]]) {
    gaps[i].erase(gaps[i].begin() + j);
    return true;
  }
  return false;
}
int solve() {
  set_gaps();
  int res = 0;
  for (int i=0;i<gaps.size();i++) {
    if (gaps[i].size() % fr == 1) {
      bool flag = false;
      for (int j=0;j<gaps[i].size();j++) {
        if (!erase_if_pos(i, j)) {
          flag = true;
        } else
          res += bc;
      }
      if (flag)
        return -1;
    }
    /*
    for (int j=0;j<gaps[i].size();j++) {
      if (fc / fr > bc) {
        if (erase_if_pos(i, j)) {
          res += bc;
        }
      } else {

      }
    }
    */
    res += fc * (gaps[i].size() / fr);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n, m, a;
  cin >> n >> m >> fc >> fr >> bc;
  for (int i=0;i<n;i++) {
    cin >> a;
    wp.push_back(a);
  }
  for (int i=0;i<m;i++) {
    cin >> a;
    goal.push_back(a);
  }
  if (!check_possible())
    cout << -1 << endl;
  else
    cout << solve() << endl;
  return 0;
}
