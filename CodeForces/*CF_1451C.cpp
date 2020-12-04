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

int n, k;
string a, b;

bool solve() {
  int cnt[26] = {0};
  int cnt2[26] = {0};
  for (int i=0;i<n;i++) {
    cnt[a[i] - 'a']++;
    cnt2[b[i] - 'a']++;
  }
  int kcnt = 0;
  for (int i=0;i<26;i++) {
    //cout << i << " " << cnt[i] << " " << cnt2[i] << " " << kcnt << "\n";
    if (cnt[i] > cnt2[i]) {
      if ((cnt[i] - cnt2[i]) % k != 0) return false;
      else kcnt += (cnt[i] - cnt2[i]) / k;
    } else if (cnt[i] < cnt2[i]) {
      if ((cnt2[i] - cnt[i]) % k == 0 && (cnt2[i] - cnt[i]) / k <= kcnt) {
        kcnt -= (cnt2[i] - cnt[i]) / k;
      } else {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> a;
    cin >> b;
    cout << (solve() ? "Yes" : "No") << "\n";
  }
  return 0;
}
