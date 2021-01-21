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

int n;
int a[2][1001];

string solve() {
  int cnt[2] = {0};
  for (int i=0;i<n;i++) {
    if (a[0][i] > a[1][i]) cnt[0]++;
    else if (a[0][i] < a[1][i]) cnt[1]++;
  }
  if (cnt[0] > cnt[1]) return "RED";
  else if (cnt[0] < cnt[1]) return "BLUE";
  return "EQUAL";
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    char c;
    for (int i=0;i<n;i++) {
      cin >> c;
      a[0][i] = c - '0';
    }
    for (int i=0;i<n;i++) {
      cin >> c;
      a[1][i] = c - '0';
    }
    cout << solve() << "\n";
  }
  return 0;
}
