#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INFI 1e18+7
#define pb push_back
#define F first
#define S second

typedef long long ll;

using namespace std;

int n;
int a[100001];
int b[100001];
int min_num;

bool solve() {
  sort(b, b+n);
  for (int i=0;i<n;i++) {
    if (a[i] == b[i]) continue;
    else if (a[i] % min_num != 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    min_num = 1000000001;
    cin >> n;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      b[i] = a[i];
      min_num = min(min_num, a[i]);
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
