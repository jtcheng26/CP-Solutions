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

typedef long long ll;

using namespace std;

int n;
int r, p, s;
string bob;
char win[101];

bool solve() {
  int cnt = 0;
  int goal = (n + 1) / 2;
  for (int i=0;i<n;i++) {
    win[i] = 'X';
    if (bob[i] == 'S' && r > 0) {
      cnt++;
      r--;
      win[i] = 'R';
    } else if (bob[i] == 'R' && p > 0) {
      cnt++;
      p--;
      win[i] = 'P';
    } else if (bob[i] == 'P' && s > 0) {
      cnt++;
      s--;
      win[i] = 'S';
    }
  }
  for (int i=0;i<n;i++) {
    if (win[i] == 'X') {
      if (r > 0) {
        win[i] = 'R';
        r--;
      } else if (p > 0) {
        win[i] = 'P';
        p--;
      } else {
        win[i] = 'S';
        s--;
      }
    }
  }
  return cnt >= goal;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> r >> p >> s;
    cin >> bob;
    bool ans = solve();
    cout << (ans ? "YES" : "NO") << endl;
    if (ans) {
      for (int i=0;i<n;i++) {
        cout << win[i] << (i == n-1 ? "\n" : "");
      }
    }
  }
  return 0;
}
