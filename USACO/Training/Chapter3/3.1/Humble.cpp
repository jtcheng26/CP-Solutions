/*
   LANG: C++11
   PROG: humble
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <climits>

typedef long long ll;

using namespace std;

const int INFI = INT_MAX;
int k, n;
int primes[100];
int ans[100001];
int h[100] = {0};

void solve() {
  ans[0] = 1;
  for (int i=1;i<=n;i++) {
    for (int j=0;j<k;j++) {
      //cout << i << " " << primes[j] << " " << ans[h[j]] << endl;
      while (h[j] < i-1 && primes[j] * ans[h[j]] <= ans[i-1]) {
        h[j]++;
      }
    }
    int next_hum = INFI;
    for (int j=0;j<k;j++) {
      next_hum = min(next_hum, primes[j] * ans[h[j]]);
    }
    //cout << next_hum << endl;
    ans[i] = next_hum;
  }
}

int main() {
  ofstream cout ("humble.out");
  ifstream cin ("humble.in");
  cin >> k >> n;
  for (int i=0;i<k;i++) {
    cin >> primes[i];
  }
  solve();
  cout << ans[n] << endl;
  return 0;
}
