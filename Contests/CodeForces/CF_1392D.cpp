#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define L 0
#define R 1
#define INFI 100000007

typedef long long ll;

using namespace std;

int n;
int a[200001][2]; // players attacking
int d[200001][2]; // being attacked by
char s[200002];

int solve() {
  int st = 0;
  char seq[n];
  for (int i=n;i>=1;i--) {
    if (s[i] != s[i+1]) {
      if (i < n) st = i + 1;
      else st = 1;
      break;
    }
  }
  int c = 0;
  if (st == 0) return (n + 2) / 3;
  for (int i=st;i<=n;i++) {
    seq[c++] = s[i];
    //cout << seq[c-1] << " ";
  }
  for (int i=1;i<st;i++) {
    seq[c++] = s[i];
    //cout << seq[c-1] << " ";
  }
  //cout << endl;
  int res = 0;
  int cnt = 1;
  for (int i=1;i<n;i++) {
    if (seq[i] == seq[i-1]) cnt++;
    else {
      res += (cnt / 3);
      cnt = 1;
    }
  }
  res += cnt / 3;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      char c;
      cin >> c;
      s[i+1] = c;
      if (c == 'R') {
        a[i][1] = 1;
        a[i][0] = 0;
        int idx = i+1;
        if (idx == n) idx = 0;
        d[idx][0] = 1;
      }
      else if (c == 'L') {
        a[i][0] = 1;
        a[i][1] = 0;
        int idx = i-1;
        if (idx == -1) idx = n-1;
        d[idx][1] = 1;
      }
    }
    s[0] = s[n];
    s[n+1] = s[1];
    cout << solve() << endl;
  }
  return 0;
}
