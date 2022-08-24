#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct award {
  int p, k, a;
};

int n, b;
award as[26];
int a[26][26];
int dp[1 << 20];
int aw[26][40006];

/*

dp[i][j] = max points with first i events and bitmask of cows j
aw[i][k] = max award earned for k points at event i and earlier - precomp
a[c][i] = points of cow c at event i - input

dp[i][j] = max over previous j (pj) (dp[i][pj] + aw[i][dp[i][pj] + a[c][i]])

for aw[i][k], only consider awards where K_i = i
*/

bool in(int i, int bm) { return bm & (1 << --i); }

int without(int i, int bm) { return bm ^ (1 << --i); }

int go(int bm) {
  if (dp[bm] || bm == 0) return dp[bm];
  int i = 0;
  for (int j = 1; j <= n; j++) {
    if (in(j, bm)) {
      i++;
    }
  }
  for (int j = 1; j <= n; j++) {
    if (in(j, bm)) {
      int prev = go(without(j, bm));
      dp[bm] = max(dp[bm], prev + a[j][i]);
    }
  }
  dp[bm] += aw[i][dp[bm]];
  return dp[bm];
}

int solve() {
  for (int i = 1; i <= n; i++) { // can optimize by sorting but whatever lmao
    for (int j = 0; j < b; j++) {
      if (as[j].k != i)
        continue;
      aw[i][as[j].p] += as[j].a;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 40000; j++) {
      aw[i][j] += aw[i][j - 1];
    }
  }

  return go((1 << n) - 1);
}

int main() {
  ofstream cout ("dec.out");
  ifstream cin ("dec.in");
  cin >> n >> b;
  for (int i = 0; i < b; i++) {
    cin >> as[i].k >> as[i].p >> as[i].a;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  cout << solve() << endl;
  return 0;
}
