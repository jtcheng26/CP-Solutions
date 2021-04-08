/*
   LANG: C++11
   PROG: nuggets
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define INFI 2000000001;
#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int sizes[11];
const int MAXN = 256*256;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

bool test_coprimes() {
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      int g = gcd(sizes[i], sizes[j]);
      if (g == 1) return true;
    }
  }
  return false;
}

int solve() {
  int res = 0;
  bool dp[MAXN] = {0};
  dp[0] = true;
  if (!test_coprimes()) return false; // if no coprimes, it is impossible
  for (int i=0;i<n;i++) {
    for (int j=1;j<MAXN;j++) {
      if (j < sizes[i]) continue;
      dp[j] = dp[j] || dp[j-sizes[i]];
    }
  }
  for (int i=1;i<MAXN;i++)
    if (!dp[i]) res = i;
  return res;
}

int main() {
  ofstream cout ("nuggets.out");
  ifstream cin ("nuggets.in");
  cin >> n;
  for (int i=0;i<n;i++) cin >> sizes[i];
  cout << solve() << endl;
  return 0;
}
