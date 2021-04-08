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

typedef long long ll;

using namespace std;

ll n;
string key = "codeforces";

string solve() {
  string res = "";
  ll mx = 1;
  int cnt[10];
  for (int i=0;i<10;i++) cnt[i] = 1;
  while (mx < n) {
    for (int i=0;i<10;i++) {
      if (mx < n) cnt[i]++;
      else break;
      mx = (mx * (cnt[i])) / (cnt[i] - 1);
    }
  }
  for (int i=0;i<10;i++) {
    for (int j=0;j<cnt[i];j++)
      res += key.substr(i, 1);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  cout << solve() << endl;
  return 0;
}
