#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

#define INF 1000000001
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007

typedef long long ll;

using namespace std;

int n, k;
string s;

string solve() {
  string res = s;
  int cnt[26] = {0};
  for (int i=0;i<n;i++) cnt[s[i] - 'a']++;
  int need = 0;
  for (int i=0;i<26;i++) {
    need += (k - (cnt[i] % k)) % k;
  }
  if (need == 0) return res;
  //cout << need << "\n";
  for (int i=n-1;i>=0;i--) {
    int have = n - i - 1;
    cnt[s[i] - 'a']--;
    if (cnt[s[i] - 'a'] % k == 0) need -= (k-1);
    else need++;
    for (int j=(s[i] - 'a')+1;j<26;j++) {
      int ne = need;
      cnt[j]++;
      if (cnt[j] % k == 1) {
        ne = need + (k-1);
      } else {
        ne = need - 1;
      }
      //cout << i << " " << j << " " << have << " " << ne << "\n";
      if (have >= ne && (have - ne) % k == 0) {
        res[i] = (char) (j + 'a');
        int rem = have - ne;
        for (int l=i+1;l<n;l++) {
          if (rem > 0) {
            res[l] = 'a';
            rem--;
          } else {
            for (int m=0;m<26;m++) {
              if (cnt[m] % k != 0) {
                cnt[m]++;
                res[l] = (char) (m + 'a');
                break;
              }
            }
          }
        }
        return res;
      }
      cnt[j]--;
    }
  }
  return "-1";
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> s;
    cout << solve() << "\n";
  }
  return 0;
}
