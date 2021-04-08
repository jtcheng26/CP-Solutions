#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int x, y;
string res = "";

int mod2(int k) {
  return abs(k) % 2;
}

void go(int x, int y) {
  if (x == 1 && y == 0) res += "E";
  else if (x == -1 && y == 0) res += "W";
  else if (x == 0 && y == 1) res += "N";
  else if (x == 0 && y == -1) res += "S";
  else if (mod2(x) == 1) {
    if (mod2((x + 1) / 2) != mod2(y / 2)) {
      res += "W";
      go((x + 1) / 2, y / 2);
    } else {
      res += "E";
      go((x - 1) / 2, y / 2);
    }
  } else {
    if (mod2((y + 1) / 2) != mod2(x / 2)) {
      res += "S";
      go(x / 2, (y + 1) / 2);
    } else {
      res += "N";
      go(x / 2, (y - 1) / 2);
    }
  }
}

string solve() {
  res = "";
  if (mod2(x) == mod2(y)) return "IMPOSSIBLE";
  go(x, y);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  for (int z=1;z<=t;z++) {
    cin >> x >> y;
    cout << "Case #" << z << ": " << solve() << "\n";
  }
  return 0;
}