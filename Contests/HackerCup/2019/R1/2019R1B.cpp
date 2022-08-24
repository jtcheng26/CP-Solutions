#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
string s;

ll solve() {
  ll res = 0;
  ll cost[n];
  cost[0] = 2;
  for (int i=1;i<n;i++) {
    cost[i] = (cost[i-1] * 2) % MOD;
  }
  int cnt = 0;
  for (int i=n-1;i>=0;i--) {
    if (s[i] == 'B') {
      if (cnt == k) {
        res = (res + cost[i]) % MOD;
        if (cnt > 0) cnt--;
      } else cnt++;
    }
    else if (cnt > 0) cnt--;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  ifstream cin ("class_treasurer_input.txt");
  ofstream cout ("2019R1B.txt");
  int t;
  cin >> t;//
  for (int i=1;i<=t;i++) {
    cin >> n >> k;
    cin >> s;
    cout << "Case #" << i << ": " << solve() << endl;//
  }
  return 0;
}
