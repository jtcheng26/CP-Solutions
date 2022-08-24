#include <iostream>
#include <fstream>
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

double p;
ll facts[21];

ll factorial(int f) {
  if (f == 0) return 1;
  facts[0] = 1;
  ll ans = 1;
  for (int i=1;i<=f;i++) {
    ans *= i;
    facts[i] = ans;
  }
  return ans;
}

double solve() {
  int L = 5000;
  double res = 0;
  double dp[L][21]; // prob of getting at least j bars after i attempts
  factorial(20);
  dp[0][0] = 1;
  for (int i=1;i<=20;i++) dp[0][i] = 0;
  for (int i=1;i<L;i++) {
    for (int j=0;j<=20;j++) {
      dp[i][j] = 0;
      for (int k=0;k<=j;k++) {
        //cout << 20-k << " " << j - k << " " << 20 - k - (j - k) << endl;
        double add = dp[i-1][k] * ((double)facts[20 - k] / (double)facts[j - k] / (double)facts[20 - k - (j - k)]);
        add *= pow(p, j - k);
        add *= pow(1 - p, 20 - j);
        //cout << add << endl;
        dp[i][j] += add;
      }
    }
  }

  double win[L]; // prob of getting 20th bar on ith attempt
  for (int i=1;i<L;i++) {
    win[i] = dp[i][20] - dp[i-1][20];
  }
  for (int i=1;i<L;i++) {
    res += (i * win[i]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("all_critical_input.txt");
  ofstream cout ("2015R2B.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> p;
    cout << fixed;
    cout << setprecision(5);
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
