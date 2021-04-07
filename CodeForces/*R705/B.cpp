#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;// bad: 3, 4, 6, 7, 9
int h;
int m;

int rev(int a) {
  if (a == 1 || a == 0 || a == 8) return a;
  if (a == 2) return 5;
  if (a == 5) return 2;
}

void solve() {
  int badh[100] = {false};
  int badm[100] = {false};
  for (int i=0;i<100;i++) {
    int one = (i % 10);
    if (one == 3 || one == 4 || one == 6 || one == 7 || one == 9) badh[i] = badm[i] = true;
    int ten = (i / 10);
    if (ten == 3 || ten == 4 || ten == 6 || ten == 7 || ten == 9) badh[i] = badm[i] = true;
    if (!badm[i]) {
      if (rev(one) * 10 + rev(ten) >= n) badm[i] = true;
    }
    if (!badh[i]) {
      if (rev(one) * 10 + rev(ten) >= k) badh[i] = true;
    }
  }
  while (badm[m] || badh[h]) {
    //cout << m << "\n";
    m++;
    if (m == k) {
      m = 0;
      h = (h + 1) % n;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> h;
    char c;
    cin >> c;
    cin >> m;
    solve();
    if (h < 10) cout << "0";
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m << "\n";
  }
  return 0;
}
