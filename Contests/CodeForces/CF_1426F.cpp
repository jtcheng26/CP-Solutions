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
#define MOD 1000000007;

typedef long long ll;

using namespace std;

int n;
char s[200001];
ll threePow[200001];

void tPow() {
  threePow[0] = 1;
  for (int i=1;i<n;i++) {
    threePow[i] = (threePow[i-1] * 3) % MOD;
    //cout << threePow[i] << endl;
  }
}

ll solve(int cnt) {
  tPow();
  ll res = 0;
  ll c[2][n];
  c[0][n-1] = s[n-1] == 'c';
  c[1][n-1] = s[n-1] == '?';
  for (int i=n-2;i>=2;i--) {
    if (s[i] == 'c') {
      c[0][i] = c[0][i+1] + 1;
      c[1][i] = c[1][i+1];
    }
    else if (s[i] == '?') {
      c[0][i] = c[0][i+1];
      c[1][i] = c[1][i+1] + 1;
    }
    else {
      c[0][i] = c[0][i+1];
      c[1][i] = c[1][i+1];
    }
    //cout << i << ": " << c[0][i] << " " << c[1][i] << endl;
  }
  ll b[3][n];
  b[0][n-2] = s[n-2] == 'b' ? c[0][n-1] : 0;
  b[1][n-2] = s[n-2] == 'b' ? c[1][n-1] : s[n-2] == '?' ? c[0][n-1] : 0;
  b[2][n-2] = s[n-2] == '?' ? c[1][n-1] : 0;
  for (int i=n-3;i>=1;i--) {
    if (s[i] == 'b') {
      b[0][i] = (b[0][i+1] + c[0][i+1]) % MOD;
      b[1][i] = (b[1][i+1] + c[1][i+1]) % MOD;
      b[2][i] = b[2][i+1];
    } else if (s[i] == '?') {
      b[0][i] = b[0][i+1];
      b[1][i] = (b[1][i+1] + c[0][i+1]) % MOD;
      b[2][i] = (b[2][i+1] + c[1][i+1]) % MOD;
    } else {
      b[0][i] = b[0][i+1];
      b[1][i] = b[1][i+1];
      b[2][i] = b[2][i+1];
    }
    //cout << i << ": " << b[0][i] << " " << b[1][i] << " " << b[2][i] << endl;
  }
  for (int i=n-3;i>=0;i--) {
    //cout << res << endl;
    if (s[i] == 'a') {
      res += (b[0][i+1] * threePow[cnt]) % MOD;
      res %= MOD;
      if (cnt >= 1) {
        res += (b[1][i+1] * threePow[cnt-1]) % MOD;
        res %= MOD;
      }
      if (cnt >= 2) {
        res += (b[2][i+1] * threePow[cnt-2]) % MOD;
        res %= MOD;
      }
    } else if (s[i] == '?') {
      if (cnt >= 1) {
        res += (b[0][i+1] * threePow[cnt-1]) % MOD;
        res %= MOD;
      }
      if (cnt >= 2) {
        res += (b[1][i+1] * threePow[cnt-2]) % MOD;
        res %= MOD;
      }
      if (cnt >= 3) {
        res += (b[2][i+1] * threePow[cnt-3]) % MOD;
        res %= MOD;
      }
    }
    //cout << res << endl;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  int cnt = 0;
  for (int i=0;i<n;i++) {
    cin >> s[i];
    if (s[i] == '?') cnt++;
  }
  cout << solve(cnt) << "\n";
  return 0;
}
