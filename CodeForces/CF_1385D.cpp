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
char s[131073];
int cnt[262147][26]; // binary-indexed letter count

void build(int l, int r, int index) {
  if (r - l == 1) {
    cnt[index][s[l] - 'a']++;
    return;
  }
  int mid = (r + l) / 2;
  build(l, mid, 2 * index + 1);
  build(mid, r, 2 * index + 2);
  for (int i=0;i<26;i++) {
    cnt[index][i] = cnt[2 * index + 1][i] + cnt[2 * index + 2][i];
  }
}

int sch(int l, int r, char c, int index) {
  if (r - l == 1) return s[l] != c;
  int mid = (l + r) / 2;
  int lcnt = (mid - l) - cnt[2 * index + 1][c - 'a'];
  int rcnt = (r - mid) - cnt[2 * index + 2][c - 'a'];
  //cout << "letter " << c << " lcnt " << lcnt << " rcnt " << rcnt << endl;
  lcnt += sch(mid, r, c+1, 2 * index + 2);
  rcnt += sch(l, mid, c+1, 2 * index + 1);
  return min(lcnt, rcnt);
}

int solve() {
  int res = 0;
  for (int i=0;i<2*n;i++) {
    for (int j=0;j<26;j++)
      cnt[i][j] = 0;
  }
  build(0, n, 0);
  return sch(0, n, 'a', 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) cin >> s[i];
    cout << solve() << endl;
  }
  return 0;
}
