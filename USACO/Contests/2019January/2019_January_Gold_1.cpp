#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

struct word {
  int s, c;
};

int n, m, k;
word words[5001];
char rhyme[100001];

ll exp(int base, int power){
   if (power == 0) return 1;
   if (power == 1) return (base + MOD) % MOD;
   ll ans = exp(base,power/2);
   ans = (ans * ans + MOD) % MOD;
   if (power%2 == 1) ans = (ans*base + MOD) % MOD;
   return (ans + MOD) % MOD;
}

ll solve() {
  ll res = 0;
  ll dp[k+1];
  dp[0] = 1;
  ll r[n+1];
  for (int i=1;i<=k;i++) dp[i] = 0;
  for (int i=0;i<=n;i++) r[i] = 0;
  for (int j=0;j<=k;j++) {
    for (int i=0;i<n;i++) {
      if (j < words[i].s) continue;
      if (j == k) {
        r[words[i].c] += dp[j-words[i].s];
        r[words[i].c] %= MOD;
      } else {
        dp[j] += dp[j-words[i].s];
        dp[j] %= MOD;
      }
    }
  }
  //for (int i=0;i<=k;i++) cout << dp[i] << (i==k ? "\n" : " ");
  //for (int i=0;i<=n;i++) cout << r[i] << (i==n ? "\n" : " ");
  int classSize[100001] = {0};
  for (int i=0;i<m;i++) {
    classSize[rhyme[i] - 'A']++;
  }
  vector<int> classes;
  for (int i=0;i<100001;i++) {
    if (classSize[i] > 0) classes.pb(classSize[i]);
  }
  vector<int> ways;
  for (int i=0;i<=n;i++) {
    if (r[i] > 0) ways.pb(r[i]);
  }
  ll mult[classes.size()];
  for (int i=0;i<classes.size();i++) {
    mult[i] = 0;
    for (int j=0;j<ways.size();j++) {
      mult[i] += exp(ways[j], classes[i]);
      mult[i] %= MOD;
    }
    //cout << mult[i] << "\n";
  }
  res = 1;
  for (int i=0;i<classes.size();i++) {
    res *= mult[i];
    res %= MOD;
  }
  return res;
}

int main() {
  ofstream cout ("poetry.out");
  ifstream cin ("poetry.in");
  cin >> n >> m >> k;
  for (int i=0;i<n;i++) cin >> words[i].s >> words[i].c;
  for (int i=0;i<m;i++) {
    cin >> rhyme[i];
  }
  cout << solve() << "\n";
  return 0;
}
