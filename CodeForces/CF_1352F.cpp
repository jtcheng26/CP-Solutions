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

int cnt[3];

string solve() {
  string res = "";
  if (cnt[0] > 0) {
    res = "0";
  }
  for (int j=0;j<cnt[0];j++) {
    res += "0";
  }
  if (res.length() > 0 && cnt[2] > 0) cnt[1]--;
  if (cnt[2] > 0) res += "1";
  for (int j=0;j<cnt[2];j++) {
    res += "1";
  }
  if (res.length() == 0) res = "0";
  for (int j=0;j<cnt[1];j++) {
    if (res[res.length()-1] == '0') res += "1";
    else res += "0";
  }

  return res;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    cout << solve() << endl;
  }
  return 0;
}
