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
#define MOD 1000000007

typedef unsigned long long ll;

using namespace std;

int n;
int digit[100001];
ll tenPow[100001];

void modTen() {
  tenPow[0] = 1;
  for (int i=1;i<n;i++) {
    tenPow[i] = (tenPow[i-1] * 10) % MOD;
  }
}

int solve() {
  modTen();
  ll res = 0;
  ll pfx[n];
  ll sfx[n];
  ll pfxTens[n];
  ll sfxSum[n];
  pfx[0] = digit[0];
  pfxTens[0] = 0;
  for (int i=1;i<n;i++) {
    pfx[i] = (pfx[i-1] * 10 + digit[i]) % MOD;
    pfxTens[i] = (pfxTens[i-1] + tenPow[i]) % MOD;
  }
  sfx[n-1] = digit[n-1];
  sfxSum[n-1] = digit[n-1];
  for (int i=n-2;i>=0;i--) {
    sfx[i] = (tenPow[n-i-1] * digit[i] + sfx[i+1]) % MOD;
    sfxSum[i] = (sfxSum[i+1] + sfx[i]) % MOD;
  }
  //for (int i=0;i<n;i++) cout << pfx[i] << (i == n-1 ? "\n" : " ");
  //for (int i=n-1;i>=0;i--) cout << sfx[i] << (i == 0 ? "\n" : " ");
  for (int i=0;i<n;i++) {
    if (i < n-1) {
      res += pfx[i];
      res %= MOD;
    }
    if (i > 0) {
      res += sfx[i];
      res %= MOD;
    }
  }
  for (int i=0;i<n-2;i++) {
    ll pf = pfx[i];
    res += ((pf * pfxTens[n-2-i]) % MOD + sfxSum[i+2]) % MOD;
    res %= MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  string s;
  cin >> s;
  for (int i=0;i<s.length();i++)
    digit[i] = s[i] - '0';
  n = s.length();
  cout << solve() << endl;
  return 0;
}
