#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, m;

vector<int> make_primes(int limit) {
  vector<int> primes;
  for (int i=0;i<=limit; i++)
    primes.push_back(true);
  primes[0] = primes[1] = false;
  for (int i=2;i*i<=limit;i++){
    if (primes[i]){
      for (int k=limit/i,j=i*k;k>=i;k--,j-=i){
        if (primes[k])
          primes[j] = false;
      }
    }
  }
  vector<int> ret;
  for (int i=0;i<=limit;i++) {
    if (primes[i]) ret.push_back(i);
  }
  return ret;
}

ll solve() {
  vector<int> primes = make_primes(n);
  ll dp[primes.size()+1][n+1];
  for (int i=0;i<=n;i++) {
    for (int j=0;j<=primes.size();j++) {
      dp[j][i] = 0;
    }
    dp[0][i] = 1;
  }
  for (int i=1;i<=primes.size();i++) {
    for (int j=0;j<=n;j++) {
      dp[i][j] = dp[i-1][j];
      ll p = primes[i-1];
      while (p <= j) {
        dp[i][j] = (dp[i][j] + (p * dp[i-1][j-p]) % m) % m;
        p *= primes[i-1];
      }
    }
  }
  return dp[primes.size()][n];
}

int main() {
  ofstream cout ("exercise.out");
  ifstream cin ("exercise.in");
  cin >> n >> m;
  cout << solve() << endl;
  return 0;
}
