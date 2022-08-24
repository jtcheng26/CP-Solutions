#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <iomanip>

#define INF 1000000001
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n;
double v, x;

string solve() {
  if (v >= x) {
    return "SWERVE";
  }
  if (v * 5 >= x) {
    return "BRAKE";
  }
  return "SAFE";
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i=0;i<n;i++) {
    string s;
    cin >> s;
    v = stod(s.substr(0, s.find(":")));
    x = stod(s.substr(s.find(":") + 1));
    cout << solve() << "\n";
  }
  return 0;
}