#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <climits>

#define INFI ULLONG_MAX
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef unsigned long long ll;

using namespace std;

int n[3];
ll cnt[3][100001];

ll sq(ll a) {
  return a * a;
}

pair<ll, ll> binSch(ll k, int color) {
  int l = 0;
  int r = n[color];
  while (l < r) {
    int mid = (l + r) / 2;
    if (cnt[color][mid] < k) {
      l = mid + 1;
    } else if (cnt[color][mid] > k) {
      r = mid;
    } else {
      return mp(k, k);
    }
  }
  pair<ll, ll> res;
  if (l > 0 && cnt[color][l-1] <= k) res.F = cnt[color][l-1];
  else res.F = 0;
  if (l < n[color] && cnt[color][l] >= k) res.S = cnt[color][l];
  else res.S = 0;
  return res;
}

ll solveForMid(int low, int mid, int high) {
  ll res = INFI;
  for (int i=0;i<n[mid];i++) {
    ll l = binSch(cnt[mid][i], low).F;
    ll h = binSch(cnt[mid][i], high).S;
    if (l == 0 || h == 0) continue;
    //cout << "lmh: " << l << " " << cnt[mid][i] << " " << h << "\n";
    res = min(res, sq(cnt[mid][i] - l) + sq(cnt[mid][i] - h) + sq(h - l));
  }
  return res;
}

ll solve() {
  ll res = INFI;
  int perm[3] = { 0, 1, 2 };
  for (int i=0;i<3;i++) sort(cnt[i], cnt[i]+n[i]);
  do {
    res = min(res, solveForMid(perm[0], perm[1], perm[2]));
  } while (next_permutation(perm, perm+3));
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n[0] >> n[1] >> n[2];
    for (int i=0;i<3;i++) {
      for (int j=0;j<n[i];j++) {
        cin >> cnt[i][j];
      }
    }
    cout << solve() << "\n";
  }
  return 0;
}
