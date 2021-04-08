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
#define MOD 1e9+7

typedef long long ll;

using namespace std;

string s;

int solve() {
  int res = 0;
  int curr = 1;
  for (int i=1;i<s.length();i++) {
    if (s[i] == s[i-1]) curr++;
    else {
      res = max(res, curr);
      curr = 1;
    }
  }
  res = max(res, curr);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> s;
  cout << solve() << "\n";
  return 0;
}
