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

int solve() {
  int res = 0;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int cnt[2] = {0};
    for (int i=0;i<n;i++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    if (cnt[0] % 2 == 0 || n == 2 || cnt[1] == cnt[0]) cout << max(cnt[0], cnt[1]) << endl;
    else cout << max(cnt[0], cnt[1]) - 1 << endl;
    if (cnt[0] >= cnt[1]) {
      for (int i=0;i<cnt[0]-1;i++) cout << 0 << " ";
      if (cnt[0] % 2 == 0 || cnt[0] == cnt[1]) cout << 0 << "\n";
      else cout << "\n";
    } else {
      for (int i=0;i<cnt[1]-1;i++) cout << 1 << " ";
      if (cnt[1] % 2 == 0 || cnt[1] == 1) cout << 1 << "\n";
      else cout << "\n";
    }
  }
  return 0;
}
