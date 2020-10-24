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

int n;
int a[200001];

int solve() {
  int res = 0;
  int cnt = 1;
  vector<int> segments;
  for (int i=1;i<n;i++) {
    if (a[i] == a[i-1]) cnt++;
    else {
      segments.pb(cnt);
      cnt = 1;
    }
  }
  if (cnt > 0) segments.pb(cnt);
  int half = 0;
  for (int i=0;i<segments.size();i++) {
    if (segments[i] > 1) {
      res += 2;
      int change = half - max(0, half - (segments[i] - 2));
      res += change * 2;
      half = max(0, half - (segments[i] - 2));
    }
    else {
      half++;
    }
  }
  res += half;
  return (res + 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0;i<n;i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
    }
    cout << solve() << endl;
  }
  return 0;
}
