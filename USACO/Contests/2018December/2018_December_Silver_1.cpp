#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n, m, c;
int a[100001];

bool valid (int ans) {
  int car = 0;
  int cnt = 0;
  int start = 0;
  //cout << "TRYING " << ans << endl;
  for (int i=0;i<n;i++) {
    if (cnt == 0) {
      start = a[i];
      car++;
    }
    cnt++;
    //cout << a[i] << " " << a[i] - start << endl;
    if (a[i] - start > ans) {
      cnt = 1;
      car++;
      start = a[i];
    }
    else if (cnt == c) {
      cnt = 0;
    }
    if (car > m) return false;
  }
  return true;
}

int solve() {
  sort(a, a+n);
  int res = 0;
  int l = 0;
  int r = 1000000001;
  while (l < r) {
    int mid = (l + r) / 2;
    if (valid(mid)) {
      res = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return res;
}

int main() {
  ofstream cout ("convention.out");
  ifstream cin ("convention.in");
  cin >> n >> m >> c;
  for (int i=0;i<n;i++) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
